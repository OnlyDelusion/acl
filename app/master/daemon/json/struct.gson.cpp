#include "stdafx.h"
#include "struct.h"
#include "struct.gson.h"
#include "acl_cpp/serialize/gson_helper.ipp"
namespace acl
{
    acl::json_node& gson(acl::json &$json, const list_req_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.cmd))
            $node.add_null("cmd");
        else
            $node.add_text("cmd", acl::get_value($obj.cmd));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const list_req_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const list_req_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, list_req_t &$obj)
    {
        acl::json_node *cmd = $node["cmd"];
        std::pair<bool, std::string> $result;

        if(!cmd ||!($result = gson(*cmd, &$obj.cmd), $result.first))
            return std::make_pair(false, "required [list_req_t.cmd] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, list_req_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, list_req_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const list_res_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.status))
            $node.add_null("status");
        else
            $node.add_number("status", acl::get_value($obj.status));

        if (check_nullptr($obj.msg))
            $node.add_null("msg");
        else
            $node.add_text("msg", acl::get_value($obj.msg));

        if (check_nullptr($obj.data))
            $node.add_null("data");
        else
            $node.add_child("data", acl::gson($json, $obj.data));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const list_res_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const list_res_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, list_res_t &$obj)
    {
        acl::json_node *status = $node["status"];
        acl::json_node *msg = $node["msg"];
        acl::json_node *data = $node["data"];
        std::pair<bool, std::string> $result;

        if(!status ||!($result = gson(*status, &$obj.status), $result.first))
            return std::make_pair(false, "required [list_res_t.status] failed:{"+$result.second+"}");
     
        if(!msg ||!($result = gson(*msg, &$obj.msg), $result.first))
            return std::make_pair(false, "required [list_res_t.msg] failed:{"+$result.second+"}");
     
        if(!data ||!data->get_obj()||!($result = gson(*data->get_obj(), &$obj.data), $result.first))
            return std::make_pair(false, "required [list_res_t.data] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, list_res_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, list_res_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const req_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.cmd))
            $node.add_null("cmd");
        else
            $node.add_text("cmd", acl::get_value($obj.cmd));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const req_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const req_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, req_t &$obj)
    {
        acl::json_node *cmd = $node["cmd"];
        std::pair<bool, std::string> $result;

        if(!cmd ||!($result = gson(*cmd, &$obj.cmd), $result.first))
            return std::make_pair(false, "required [req_t.cmd] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, req_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, req_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const res_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.status))
            $node.add_null("status");
        else
            $node.add_number("status", acl::get_value($obj.status));

        if (check_nullptr($obj.msg))
            $node.add_null("msg");
        else
            $node.add_text("msg", acl::get_value($obj.msg));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const res_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const res_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, res_t &$obj)
    {
        acl::json_node *status = $node["status"];
        acl::json_node *msg = $node["msg"];
        std::pair<bool, std::string> $result;

        if(!status ||!($result = gson(*status, &$obj.status), $result.first))
            return std::make_pair(false, "required [res_t.status] failed:{"+$result.second+"}");
     
        if(!msg ||!($result = gson(*msg, &$obj.msg), $result.first))
            return std::make_pair(false, "required [res_t.msg] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, res_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, res_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const serv_info_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.status))
            $node.add_null("status");
        else
            $node.add_number("status", acl::get_value($obj.status));

        if (check_nullptr($obj.name))
            $node.add_null("name");
        else
            $node.add_text("name", acl::get_value($obj.name));

        if (check_nullptr($obj.type))
            $node.add_null("type");
        else
            $node.add_number("type", acl::get_value($obj.type));

        if (check_nullptr($obj.owner))
            $node.add_null("owner");
        else
            $node.add_text("owner", acl::get_value($obj.owner));

        if (check_nullptr($obj.path))
            $node.add_null("path");
        else
            $node.add_text("path", acl::get_value($obj.path));

        if (check_nullptr($obj.proc_max))
            $node.add_null("proc_max");
        else
            $node.add_number("proc_max", acl::get_value($obj.proc_max));

        if (check_nullptr($obj.proc_prefork))
            $node.add_null("proc_prefork");
        else
            $node.add_number("proc_prefork", acl::get_value($obj.proc_prefork));

        if (check_nullptr($obj.proc_total))
            $node.add_null("proc_total");
        else
            $node.add_number("proc_total", acl::get_value($obj.proc_total));

        if (check_nullptr($obj.proc_avail))
            $node.add_null("proc_avail");
        else
            $node.add_number("proc_avail", acl::get_value($obj.proc_avail));

        if (check_nullptr($obj.throttle_delay))
            $node.add_null("throttle_delay");
        else
            $node.add_number("throttle_delay", acl::get_value($obj.throttle_delay));

        if (check_nullptr($obj.listen_fd_count))
            $node.add_null("listen_fd_count");
        else
            $node.add_number("listen_fd_count", acl::get_value($obj.listen_fd_count));

        if (check_nullptr($obj.notify_addr))
            $node.add_null("notify_addr");
        else
            $node.add_text("notify_addr", acl::get_value($obj.notify_addr));

        if (check_nullptr($obj.notify_recipients))
            $node.add_null("notify_recipients");
        else
            $node.add_text("notify_recipients", acl::get_value($obj.notify_recipients));

        if (check_nullptr($obj.env))
            $node.add_null("env");
        else
            $node.add_child("env", acl::gson($json, $obj.env));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const serv_info_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const serv_info_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, serv_info_t &$obj)
    {
        acl::json_node *status = $node["status"];
        acl::json_node *name = $node["name"];
        acl::json_node *type = $node["type"];
        acl::json_node *owner = $node["owner"];
        acl::json_node *path = $node["path"];
        acl::json_node *proc_max = $node["proc_max"];
        acl::json_node *proc_prefork = $node["proc_prefork"];
        acl::json_node *proc_total = $node["proc_total"];
        acl::json_node *proc_avail = $node["proc_avail"];
        acl::json_node *throttle_delay = $node["throttle_delay"];
        acl::json_node *listen_fd_count = $node["listen_fd_count"];
        acl::json_node *notify_addr = $node["notify_addr"];
        acl::json_node *notify_recipients = $node["notify_recipients"];
        acl::json_node *env = $node["env"];
        std::pair<bool, std::string> $result;

        if(!status ||!($result = gson(*status, &$obj.status), $result.first))
            return std::make_pair(false, "required [serv_info_t.status] failed:{"+$result.second+"}");
     
        if(!name ||!($result = gson(*name, &$obj.name), $result.first))
            return std::make_pair(false, "required [serv_info_t.name] failed:{"+$result.second+"}");
     
        if(!type ||!($result = gson(*type, &$obj.type), $result.first))
            return std::make_pair(false, "required [serv_info_t.type] failed:{"+$result.second+"}");
     
        if(owner)
            gson(*owner, &$obj.owner);
     
        if(!path ||!($result = gson(*path, &$obj.path), $result.first))
            return std::make_pair(false, "required [serv_info_t.path] failed:{"+$result.second+"}");
     
        if(!proc_max ||!($result = gson(*proc_max, &$obj.proc_max), $result.first))
            return std::make_pair(false, "required [serv_info_t.proc_max] failed:{"+$result.second+"}");
     
        if(!proc_prefork ||!($result = gson(*proc_prefork, &$obj.proc_prefork), $result.first))
            return std::make_pair(false, "required [serv_info_t.proc_prefork] failed:{"+$result.second+"}");
     
        if(!proc_total ||!($result = gson(*proc_total, &$obj.proc_total), $result.first))
            return std::make_pair(false, "required [serv_info_t.proc_total] failed:{"+$result.second+"}");
     
        if(!proc_avail ||!($result = gson(*proc_avail, &$obj.proc_avail), $result.first))
            return std::make_pair(false, "required [serv_info_t.proc_avail] failed:{"+$result.second+"}");
     
        if(!throttle_delay ||!($result = gson(*throttle_delay, &$obj.throttle_delay), $result.first))
            return std::make_pair(false, "required [serv_info_t.throttle_delay] failed:{"+$result.second+"}");
     
        if(!listen_fd_count ||!($result = gson(*listen_fd_count, &$obj.listen_fd_count), $result.first))
            return std::make_pair(false, "required [serv_info_t.listen_fd_count] failed:{"+$result.second+"}");
     
        if(notify_addr)
            gson(*notify_addr, &$obj.notify_addr);
     
        if(notify_recipients)
            gson(*notify_recipients, &$obj.notify_recipients);
     
        if(!env ||!env->get_obj()||!($result = gson(*env->get_obj(), &$obj.env), $result.first))
            return std::make_pair(false, "required [serv_info_t.env] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, serv_info_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, serv_info_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const start_req_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.cmd))
            $node.add_null("cmd");
        else
            $node.add_text("cmd", acl::get_value($obj.cmd));

        if (check_nullptr($obj.data))
            $node.add_null("data");
        else
            $node.add_child("data", acl::gson($json, $obj.data));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const start_req_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const start_req_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, start_req_t &$obj)
    {
        acl::json_node *cmd = $node["cmd"];
        acl::json_node *data = $node["data"];
        std::pair<bool, std::string> $result;

        if(!cmd ||!($result = gson(*cmd, &$obj.cmd), $result.first))
            return std::make_pair(false, "required [start_req_t.cmd] failed:{"+$result.second+"}");
     
        if(!data ||!data->get_obj()||!($result = gson(*data->get_obj(), &$obj.data), $result.first))
            return std::make_pair(false, "required [start_req_t.data] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, start_req_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, start_req_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const start_res_data_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.status))
            $node.add_null("status");
        else
            $node.add_number("status", acl::get_value($obj.status));

        if (check_nullptr($obj.name))
            $node.add_null("name");
        else
            $node.add_text("name", acl::get_value($obj.name));

        if (check_nullptr($obj.path))
            $node.add_null("path");
        else
            $node.add_text("path", acl::get_value($obj.path));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const start_res_data_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const start_res_data_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, start_res_data_t &$obj)
    {
        acl::json_node *status = $node["status"];
        acl::json_node *name = $node["name"];
        acl::json_node *path = $node["path"];
        std::pair<bool, std::string> $result;

        if(!status ||!($result = gson(*status, &$obj.status), $result.first))
            return std::make_pair(false, "required [start_res_data_t.status] failed:{"+$result.second+"}");
     
        if(!name ||!($result = gson(*name, &$obj.name), $result.first))
            return std::make_pair(false, "required [start_res_data_t.name] failed:{"+$result.second+"}");
     
        if(path)
            gson(*path, &$obj.path);
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, start_res_data_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, start_res_data_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const start_res_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.status))
            $node.add_null("status");
        else
            $node.add_number("status", acl::get_value($obj.status));

        if (check_nullptr($obj.msg))
            $node.add_null("msg");
        else
            $node.add_text("msg", acl::get_value($obj.msg));

        if (check_nullptr($obj.data))
            $node.add_null("data");
        else
            $node.add_child("data", acl::gson($json, $obj.data));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const start_res_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const start_res_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, start_res_t &$obj)
    {
        acl::json_node *status = $node["status"];
        acl::json_node *msg = $node["msg"];
        acl::json_node *data = $node["data"];
        std::pair<bool, std::string> $result;

        if(!status ||!($result = gson(*status, &$obj.status), $result.first))
            return std::make_pair(false, "required [start_res_t.status] failed:{"+$result.second+"}");
     
        if(!msg ||!($result = gson(*msg, &$obj.msg), $result.first))
            return std::make_pair(false, "required [start_res_t.msg] failed:{"+$result.second+"}");
     
        if(!data ||!data->get_obj()||!($result = gson(*data->get_obj(), &$obj.data), $result.first))
            return std::make_pair(false, "required [start_res_t.data] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, start_res_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, start_res_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const stat_req_data_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.name))
            $node.add_null("name");
        else
            $node.add_text("name", acl::get_value($obj.name));

        if (check_nullptr($obj.type))
            $node.add_null("type");
        else
            $node.add_number("type", acl::get_value($obj.type));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const stat_req_data_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const stat_req_data_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stat_req_data_t &$obj)
    {
        acl::json_node *name = $node["name"];
        acl::json_node *type = $node["type"];
        std::pair<bool, std::string> $result;

        if(!name ||!($result = gson(*name, &$obj.name), $result.first))
            return std::make_pair(false, "required [stat_req_data_t.name] failed:{"+$result.second+"}");
     
        if(!type ||!($result = gson(*type, &$obj.type), $result.first))
            return std::make_pair(false, "required [stat_req_data_t.type] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stat_req_data_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, stat_req_data_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const stat_req_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.cmd))
            $node.add_null("cmd");
        else
            $node.add_text("cmd", acl::get_value($obj.cmd));

        if (check_nullptr($obj.data))
            $node.add_null("data");
        else
            $node.add_child("data", acl::gson($json, $obj.data));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const stat_req_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const stat_req_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stat_req_t &$obj)
    {
        acl::json_node *cmd = $node["cmd"];
        acl::json_node *data = $node["data"];
        std::pair<bool, std::string> $result;

        if(!cmd ||!($result = gson(*cmd, &$obj.cmd), $result.first))
            return std::make_pair(false, "required [stat_req_t.cmd] failed:{"+$result.second+"}");
     
        if(!data ||!data->get_obj()||!($result = gson(*data->get_obj(), &$obj.data), $result.first))
            return std::make_pair(false, "required [stat_req_t.data] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stat_req_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, stat_req_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const stat_res_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.status))
            $node.add_null("status");
        else
            $node.add_number("status", acl::get_value($obj.status));

        if (check_nullptr($obj.msg))
            $node.add_null("msg");
        else
            $node.add_text("msg", acl::get_value($obj.msg));

        if (check_nullptr($obj.data))
            $node.add_null("data");
        else
            $node.add_child("data", acl::gson($json, $obj.data));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const stat_res_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const stat_res_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stat_res_t &$obj)
    {
        acl::json_node *status = $node["status"];
        acl::json_node *msg = $node["msg"];
        acl::json_node *data = $node["data"];
        std::pair<bool, std::string> $result;

        if(!status ||!($result = gson(*status, &$obj.status), $result.first))
            return std::make_pair(false, "required [stat_res_t.status] failed:{"+$result.second+"}");
     
        if(!msg ||!($result = gson(*msg, &$obj.msg), $result.first))
            return std::make_pair(false, "required [stat_res_t.msg] failed:{"+$result.second+"}");
     
        if(!data ||!data->get_obj()||!($result = gson(*data->get_obj(), &$obj.data), $result.first))
            return std::make_pair(false, "required [stat_res_t.data] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stat_res_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, stat_res_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const stop_req_data_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.name))
            $node.add_null("name");
        else
            $node.add_text("name", acl::get_value($obj.name));

        if (check_nullptr($obj.type))
            $node.add_null("type");
        else
            $node.add_number("type", acl::get_value($obj.type));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const stop_req_data_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const stop_req_data_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stop_req_data_t &$obj)
    {
        acl::json_node *name = $node["name"];
        acl::json_node *type = $node["type"];
        std::pair<bool, std::string> $result;

        if(!name ||!($result = gson(*name, &$obj.name), $result.first))
            return std::make_pair(false, "required [stop_req_data_t.name] failed:{"+$result.second+"}");
     
        if(!type ||!($result = gson(*type, &$obj.type), $result.first))
            return std::make_pair(false, "required [stop_req_data_t.type] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stop_req_data_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, stop_req_data_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const stop_req_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.cmd))
            $node.add_null("cmd");
        else
            $node.add_text("cmd", acl::get_value($obj.cmd));

        if (check_nullptr($obj.data))
            $node.add_null("data");
        else
            $node.add_child("data", acl::gson($json, $obj.data));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const stop_req_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const stop_req_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stop_req_t &$obj)
    {
        acl::json_node *cmd = $node["cmd"];
        acl::json_node *data = $node["data"];
        std::pair<bool, std::string> $result;

        if(!cmd ||!($result = gson(*cmd, &$obj.cmd), $result.first))
            return std::make_pair(false, "required [stop_req_t.cmd] failed:{"+$result.second+"}");
     
        if(!data ||!data->get_obj()||!($result = gson(*data->get_obj(), &$obj.data), $result.first))
            return std::make_pair(false, "required [stop_req_t.data] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stop_req_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, stop_req_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const stop_res_data_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.status))
            $node.add_null("status");
        else
            $node.add_number("status", acl::get_value($obj.status));

        if (check_nullptr($obj.name))
            $node.add_null("name");
        else
            $node.add_text("name", acl::get_value($obj.name));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const stop_res_data_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const stop_res_data_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stop_res_data_t &$obj)
    {
        acl::json_node *status = $node["status"];
        acl::json_node *name = $node["name"];
        std::pair<bool, std::string> $result;

        if(!status ||!($result = gson(*status, &$obj.status), $result.first))
            return std::make_pair(false, "required [stop_res_data_t.status] failed:{"+$result.second+"}");
     
        if(!name ||!($result = gson(*name, &$obj.name), $result.first))
            return std::make_pair(false, "required [stop_res_data_t.name] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stop_res_data_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, stop_res_data_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


    acl::json_node& gson(acl::json &$json, const stop_res_t &$obj)
    {
        acl::json_node &$node = $json.create_node();

        if (check_nullptr($obj.status))
            $node.add_null("status");
        else
            $node.add_number("status", acl::get_value($obj.status));

        if (check_nullptr($obj.msg))
            $node.add_null("msg");
        else
            $node.add_text("msg", acl::get_value($obj.msg));

        if (check_nullptr($obj.data))
            $node.add_null("data");
        else
            $node.add_child("data", acl::gson($json, $obj.data));


        return $node;
    }
    
    acl::json_node& gson(acl::json &$json, const stop_res_t *$obj)
    {
        return gson ($json, *$obj);
    }


    acl::string gson(const stop_res_t &$obj)
    {
        acl::json $json;
        acl::json_node &$node = acl::gson ($json, $obj);
        return $node.to_string ();
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stop_res_t &$obj)
    {
        acl::json_node *status = $node["status"];
        acl::json_node *msg = $node["msg"];
        acl::json_node *data = $node["data"];
        std::pair<bool, std::string> $result;

        if(!status ||!($result = gson(*status, &$obj.status), $result.first))
            return std::make_pair(false, "required [stop_res_t.status] failed:{"+$result.second+"}");
     
        if(!msg ||!($result = gson(*msg, &$obj.msg), $result.first))
            return std::make_pair(false, "required [stop_res_t.msg] failed:{"+$result.second+"}");
     
        if(!data ||!data->get_obj()||!($result = gson(*data->get_obj(), &$obj.data), $result.first))
            return std::make_pair(false, "required [stop_res_t.data] failed:{"+$result.second+"}");
     
        return std::make_pair(true,"");
    }


    std::pair<bool,std::string> gson(acl::json_node &$node, stop_res_t *$obj)
    {
        return gson($node, *$obj);
    }


     std::pair<bool,std::string> gson(const acl::string &$str, stop_res_t &$obj)
    {
        acl::json _json;
        _json.update($str.c_str());
        if (!_json.finish())
        {
            return std::make_pair(false, "json not finish error");
        }
        return gson(_json.get_root(), $obj);
    }


}///end of acl.
