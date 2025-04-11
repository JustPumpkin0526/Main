#include "cctv_bjcd.h"

struct CCTV
{
    int id; // key
    std::string bjcd;

    CCTV() : id(0), bjcd("") {}

    CCTV(int id, std::string bjcd)
    {
        this->id = id;
        this->bjcd = bjcd;
    }
};

struct CCTV_RISK
{
    int cctv_id;
    double score;

    CCTV_RISK() : cctv_id(0), score(0.0) {}

    CCTV_RISK(int cctv_id, double score)
    {
        this->cctv_id = cctv_id;
        this->score = score;
    }

    bool operator<(const CCTV_RISK& other) const {
        if (score == other.score)
            return cctv_id < other.cctv_id;
        return score > other.score;
    };
};

int cctv_bjcd()
{
    std::vector<std::vector<CCTV>> cctvs;
    std::vector<CCTV_RISK> risk_cctvs;
    int num = 5;
    std::vector<int> pos_cctvs = { 5424, 5603, 71005, 71013, 4160, 9527, 8221, 8517, 80344, 3686, 6032, 9232, 1857, 35296, 48967, 49060, 47972,
    9985, 9919, 9947 };
    std::vector<std::string> pos_bjcds = { "4183041000", "4148037000", "4165035000", "4167031000", "4155035000", "4613014000", "4182031000", "4182031000"
        , "4136025600", "4163011400", "1120010800", "4719012300", "4122010600", "4793036000", "4167035000", "4182025000", "4372025000"
        , "9972025000", "9963034000", "9911011000" };
    
    std::cout << "총 생성할 CCTV 그룹 수 : " << pos_bjcds.size() << std::endl;
    std::cout << "총 생성할 CCTV 수 : " << pos_cctvs.size()*5 << std::endl;
    cctvs.resize(pos_bjcds.size());
    for (int bjcd_id = 0; bjcd_id < pos_bjcds.size(); bjcd_id++) {
        for (int cctv_id = 0; cctv_id < 5; cctv_id++) {
            int id = pos_cctvs[bjcd_id] + cctv_id;
            std::string bjcd = pos_bjcds[bjcd_id];
            cctvs[bjcd_id].push_back({ id, bjcd });
        }
        
    }
    int size = 100;
    for (int i = 0; i < 20; i++) {
        std::cout << "Group Index : " << i+1 << std::endl;
        std::cout << "Group BJCD : " << cctvs[i][0].bjcd << std::endl;
        std::cout << "남아있는 CCTV : " << size << std::endl;
        std::cout << "생성할 CCTV : " << cctvs[i].size() << std::endl;
        /*for (int j = 0; j < 5; j++) {
            std::cout << cctvs[i][j].id << std::endl;
            std::cout << cctvs[i][j].bjcd << std::endl;
        }*/
        size -= cctvs[i].size();
    }

    
    // cctvs 100 개
    // risk_ccvs 100 개
    // 변수 생성 (type 적당한걸로)
    //4183041000
    //    5424 - 95
    //    5425 - 90
    //    5426 - 80
    //    5427 - 70
    //    5428 - 50
    //4148037000
    return 0;
}