/**
 * Copyright (C) 2015-2018
 * All rights reserved.
 *
 * AUTHOR(S)
 *   Zheng Shuxin
 *   E-mail: zhengshuxin@qiyi.com
 * 
 * VERSION
 *   Wed 14 Jun 2017 12:21:44 PM CST
 */

#pragma once
#include "json/serialize.h"

class http_client
{
public:
	http_client(acl::aio_socket_stream* client, int rw_timeout = 10);

	void wait(void);

private:
	~http_client(void);

private:
	acl::aio_socket_stream* client_;
	ACL_ASTREAM*            conn_;
	int                     rw_timeout_;
	HTTP_HDR_REQ*           hdr_req_;
	HTTP_REQ               *req_;
	http_off_t              content_length_;
	acl::json               json_;

	void reset(void);
	bool handle(void);
	bool handle_list(void);
	bool handle_stat(void);
	bool handle_stop(void);
	bool handle_start(void);

	void do_reply(int status, const acl::string& buf);

	template<typename T>
	void reply(int status, T& o)
	{
		acl::string buf;
		serialize<T>(o, buf);
		do_reply(status, buf);
	}

	static int on_head(int status, void* ctx);
	static int on_body(int status, char* data, int dlen, void* ctx);
	static int on_close(ACL_ASTREAM* conn, void* ctx);
	static int on_timeo(ACL_ASTREAM* conn, void* ctx);
};
