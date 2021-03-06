#include "StdAfx.h"
#ifndef ACL_PREPARE_COMPILE

#include "stdlib/acl_define.h"
#include "stdlib/acl_msg.h"
#include "stdlib/acl_mymalloc.h"
#include "thread/acl_pthread.h"
#include "stdlib/acl_atomic.h"

#endif

#if	defined(ACL_WINDOWS) || defined(ACL_LINUX)
# define HAS_ATOMIC
#else
# undef  HAS_ATOMIC
#endif

struct ACL_ATOMIC {
	void *value;
#ifndef HAS_ATOMIC
	acl_pthread_mutex_t lock;
#endif
};

ACL_ATOMIC *acl_atomic_new(void)
{
	ACL_ATOMIC *self = (ACL_ATOMIC*) acl_mymalloc(sizeof(ACL_ATOMIC));

#ifndef HAS_ATOMIC
	acl_pthread_mutex_init(&self->lock, NULL);
#endif
	self->value = NULL;
	return self;
}

void acl_atomic_free(ACL_ATOMIC *self)
{
	self->value = NULL;
#ifndef HAS_ATOMIC
	acl_pthread_mutex_destroy(&self->lock);
#endif
	acl_myfree(self);
}

void acl_atomic_set(ACL_ATOMIC *self, void *value)
{
#ifndef HAS_ATOMIC
	acl_pthread_mutex_lock(&self->lock);
	self->value = value;
	acl_pthread_mutex_unlock(&self->lock);
#elif	defined(ACL_WINDOWS)
	InterlockedExchangePointer((volatile PVOID*) &self->value, value);
#elif	defined(ACL_LINUX)
# if defined(__GNUC__) && (__GNUC__ >= 4)
	(void) __sync_lock_test_and_set(&self->value, value);
# else
	(void) self;
	(void) value;
	acl_msg_error("%s(%d), %s: not support!",
		 __FILE__, __LINE__, __FUNCTION__);
# endif
#endif
}

void *acl_atomic_cas(ACL_ATOMIC *self, void *cmp, void *value)
{
#ifndef HAS_ATOMIC
	void *old;

	acl_pthread_mutex_lock(&self->lock);
	old = self->value;
	if (self->value == cmp)
		self->value = value;
	acl_pthread_mutex_unlock(&self->lock);

	return old;
#elif	defined(ACL_WINDOWS)
	return InterlockedCompareExchangePointer(
		(volatile PVOID*)&self->value, value, cmp);
#elif	defined(ACL_LINUX)
# if defined(__GNUC__) && (__GNUC__ >= 4)
	return __sync_val_compare_and_swap(&self->value, cmp, value);
# else
	(void) self;
	(void) cmp;
	(void) value;
	acl_msg_error("%s(%d), %s: not support!",
		 __FILE__, __LINE__, __FUNCTION__);
	return NULL;
# endif
#endif
}

void *acl_atomic_xchg(ACL_ATOMIC *self, void *value)
{
#ifndef HAS_ATOMIC
	void *old;

	acl_pthread_mutex_lock(&self->lock);
	old = self->value;
	self->value = value;
	acl_pthread_mutex_unlock(&self->lock);

	return old;
#elif	defined(ACL_WINDOWS)
	return InterlockedExchangePointer((volatile PVOID*)&self->value, value);
#elif	defined(ACL_LINUX)
# if defined(__GNUC__) && (__GNUC__ >= 4)
	return __sync_lock_test_and_set(&self->value, value);
# else
	(void) self;
	(void) value;
	acl_msg_error("%s(%d), %s: not support!",
		 __FILE__, __LINE__, __FUNCTION__);
	return NULL;
# endif
#endif
}

void acl_atomic_int64_set(ACL_ATOMIC *self, long long n)
{
#ifndef HAS_ATOMIC
	acl_pthread_mutex_lock(&self->lock);
	*self->value = n;
	acl_pthread_mutex_unlock(&self->lock);
#elif	defined(ACL_WINDOWS)
	InterlockedExchangePointer((volatile PVOID*) self->value, n);
#elif	defined(ACL_LINUX)
# if defined(__GNUC__) && (__GNUC__ >= 4)
	(void) __sync_lock_test_and_set((long long *) self->value, n);
# else
	(void) self;
	(void) value;
	acl_msg_error("%s(%d), %s: not support!",
		 __FILE__, __LINE__, __FUNCTION__);
# endif
#endif
}

long long acl_atomic_int64_fetch_add(ACL_ATOMIC *self, long long n)
{
#ifndef HAS_ATOMIC
	acl_pthread_mutex_lock(&self->lock);
	long long v = *(long long *) self->value;
	*((long long *) self->value) = v + n;
	acl_pthread_mutex_unlock(&self->lock);
	return v;
#elif	defined(ACL_WINDOWS)
	return InterlockedExchangeAdd64((volatile LONGLONG*)&self->value, n);
#elif	defined(ACL_LINUX)
# if defined(__GNUC__) && (__GNUC__ >= 4)
	return (long long) __sync_fetch_and_add(&self->value, n);
# else
	(void) self;
	(void) n;
	acl_msg_error("%s(%d), %s: not support!",
		__FILE__, __LINE__, __FUNCTION__);
	return -1;
# endif
#endif
}

long long acl_atomic_int64_add_fetch(ACL_ATOMIC *self, long long n)
{
#ifndef HAS_ATOMIC
	acl_pthread_mutex_lock(&self->lock);
	long long v = *(long long *) self->value + n;
	*((long long *) self->value) = v;
	acl_pthread_mutex_unlock(&self->lock);
	return v;
#elif	defined(ACL_WINDOWS)
	return InterlockedExchangeAdd64((volatile LONGLONG*)&self->value, n);
#elif	defined(ACL_LINUX)
# if defined(__GNUC__) && (__GNUC__ >= 4)
	return (long long) __sync_add_and_fetch(&self->value, n);
# else
	(void) self;
	(void) n;
	acl_msg_error("%s(%d), %s: not support!",
		__FILE__, __LINE__, __FUNCTION__);
	return -1;
# endif
#endif
}
