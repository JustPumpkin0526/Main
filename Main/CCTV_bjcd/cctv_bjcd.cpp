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

    bool operator<(const CCTV_RISK& other) const {
        if (score == other.score)
            return cctv_id < other.cctv_id;
        return score > other.score;
    };
};

void cctv_bjcd()
{
    std::cout << "=============================================================================================" << std::endl;
    std::cout << "테스트 더미 데이터 셋 생성" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    std::vector<std::vector<CCTV>> cctvs; //벡터 cctv 그룹
    //std::map<int, CCTV> cctvs; //map cctv 그룹
    std::vector<CCTV_RISK> risk_cctvs;
    double rand_score;
    int multnum = 5;
    std::vector<int> pos_cctvs = { 5424, 5603, 71005, 71013, 4160, 9527, 8221, 8517, 80344, 3686, 6032, 9232, 1857, 35296, 48967, 49060, 47972,
    9985, 9919, 9947 };
    std::vector<std::string> pos_bjcds = { "4183041000", "4148037000", "4165035000", "4167031000", "4155035000", "4613014000", "4182031000", "4182031000"
        , "4136025600", "4163011400", "1120010800", "4719012300", "4122010600", "4793036000", "4167035000", "4182025000", "4372025000"
        , "9972025000", "9963034000", "9911011000" };
    
    std::cout << "총 생성할 CCTV 그룹 수 : " << pos_bjcds.size() << std::endl;
    std::cout << "총 생성할 CCTV 수 : " << pos_cctvs.size() * multnum << std::endl;
    std::cout << "=============================================================================================" << std::endl;

    //map을 사용해서 그룹 생성
    /*int size = pos_cctvs.size() * multnum;
    int group = 0;
    for (int id = 0; id < pos_bjcds.size() * multnum; id++) {
        cctvs.insert({ pos_cctvs[id / multnum] + id,{pos_cctvs[id / multnum] + id,pos_bjcds[id / multnum]} });
        if (id % multnum == 0) {
            std::cout << "Group Index : " << (id / 5) + 1 << std::endl;
            std::cout << "Group BJCD : " << pos_bjcds[id / multnum] << std::endl;
            std::cout << "남아있는 CCTV : " << size << std::endl;
            std::cout << "생성할 CCTV : " << multnum << std::endl;
            std::cout << "------------------------------------------------" << std::endl;
            size -= multnum;
            group++;
        }
    }*/

    //vector 방식을 사용한 그룹 생성 코드
    cctvs.resize(pos_bjcds.size());
    int size = pos_cctvs.size() * multnum;
    for (int bjcd_id = 0; bjcd_id < pos_bjcds.size(); bjcd_id++) {
        std::cout << "Group Index : " << bjcd_id + 1 << std::endl;
        for (int cctv_id = 0; cctv_id < multnum; cctv_id++) {
            int id = pos_cctvs[bjcd_id] + cctv_id;
            std::string bjcd = pos_bjcds[bjcd_id];
            cctvs[bjcd_id].push_back({ id, bjcd });
        }
        std::cout << "Group BJCD : " << cctvs[bjcd_id][0].bjcd << std::endl;
        std::cout << "남아있는 CCTV : " << size << std::endl;
        std::cout << "생성할 CCTV : " << cctvs[bjcd_id].size() << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        size -= cctvs[bjcd_id].size();
    }

    std::cout << "=============================================================================================" << std::endl;

    /*srand(time(NULL));
    std::cout << "생성된 CCTV 그룹 수 : " << group << std::endl;
    std::cout << "생성된 CCTV 수 : " << cctvs.size() << std::endl;
    for (int risk = 0; risk < pos_cctvs.size();risk++) {
        rand_score = rand() % 100;
        risk_cctvs.push_back({ cctvs[risk].id,rand_score });
        if (risk % 5 == 0) {
            auto it = cctvs.find();
            std::cout << "BJCD : " << cctvs[risk].bjcd << std::endl;
            std::cout << "RISK CCTVS : " << std::endl;
        }
        std::cout << "CCTV ID : " << cctvs[risk].id << "/ SCORE : " << rand_score << std::endl;
    }*/
    

    std::cout << "=============================================================================================" << std::endl;
    //risk_cctvs.resize(pos_bjcds.size());
    for (int rcid = 0; rcid < cctvs.size(); rcid++) {
        for (int risk = 0; risk < cctvs[rcid].size(); risk++) {\
            rand_score = rand() % 100;
            risk_cctvs.push_back({ cctvs[rcid][risk].id, rand_score });
        }
        std::sort(risk_cctvs.begin() + rcid* multnum, risk_cctvs.end());
    }

    for (int i = 0; i < cctvs.size(); i++) {
        std::cout << "BJCD : " << cctvs[i][0].bjcd << std::endl;
        std::cout << "RISK CCTVS : " << std::endl;
        for (int j = 0; j < cctvs[i].size(); j++) {
            std::cout << "CCTV ID : " << risk_cctvs[(i* multnum)+j].cctv_id << "/ SCORE : " << risk_cctvs[(i * multnum) + j].score << std::endl;
        }
        std::cout << "------------------------------------------------" << std::endl;
    }
    std::cout << "=============================================================================================" << std::endl;
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
}