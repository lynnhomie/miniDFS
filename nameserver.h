#ifndef _fNAME_SERVER_H
#define _NAME_SERVER_H

#include <vector>
#include "dataserver.h"
#include "filetree.h"

class NameServer{
private:
    
    FileTree fileTree_;
    int numReplicate_;
    int idCnt_;
    std::vector<std::string> parse_cmd();
public:
    static std::mutex mtx1;
    std::map<std::string, std::pair<int, int>> meta;
    std::vector<DataServer *> dataServers_;
    explicit NameServer(int numReplicate);
    void add(DataServer *server);
    void operator()();
    void heartbeatProcessing();
    
    
    
};

#endif
