#ifndef _NAME_SERVER_H
#define _NAME_SERVER_H

#include <vector>
#include <map>
#include "dataserver.h"
#include "filetree.h"

class NameServer{
private:
    std::vector<DataServer *> dataServers_;
    FileTree fileTree_;
    int numReplicate_;
    int idCnt_;
    std::vector<std::string> parse_cmd();
    std::map<std::string,bool>heartbeatStatus_; //记录数据服务器与其心跳状态的对应关系
public:
    std::map<std::string, std::pair<int, int>> meta;

    explicit NameServer(int numReplicate);
    void add(DataServer *server);
    void operator()();
};


#endif
