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

    std::map<std::string, std::vector<CCTV>> cctv_group;                                                                                          //cctv의 그룹
    std::map<int, CCTV> cctvs;                                                                                                                   //cctv 더미 데이터 모음
    std::vector<CCTV_RISK> risk_cctvs;                                                                                                          // cctv 위험도 측정
    std::map<std::string, std::vector<CCTV_RISK>> risk_bjcd;                                                                                    //cctv 위험도 bjcd 그룹
    std::vector<std::string> risk_check;                                                                                                      // 중복 확인
    double rand_score;                                                                                                                       // 스코어 랜덤 생성
    int multnum = 5;                                                                                                                        // 곱할 숫자 5로 지정함
    std::vector<int> pos_cctvs = { 5424, 5603, 71005, 71013, 4160, 9527, 3171, 8517, 80344, 3686, 6032, 9232, 1857, 35296, 48967, 49060, 47972,
    9985, 9919, 9947 };                                                                                                                   //cctv id 모음
    std::vector<std::string> pos_bjcds = { "4183041000", "4148037000", "4165035000", "4167031000", "4155035000", "4613014000", "4211034000", "4182031000"
        , "4136025600", "4163011400", "1120010800", "4719012300", "4122010600", "4793036000", "4167035000", "4182025000", "4372025000"  //법정동 코드 모음
        , "9972025000", "9963034000", "9911011000" };

    std::cout << "총 생성할 CCTV 그룹 수 : " << pos_bjcds.size() << std::endl;
    std::cout << "총 생성할 CCTV 수 : " << pos_cctvs.size() * multnum << std::endl;
    std::cout << "=============================================================================================" << std::endl;
    //cctv 데이터 모음 생성 및 그룹화 진행
    int size = pos_cctvs.size() * multnum;                                                                   //그룹 사이즈
    for (int cctv_data = 0; cctv_data < pos_cctvs.size(); cctv_data++) {                                     //cctvid 모음의 크기 만큼 반복 (20회 반복)
        std::cout << "Group Index : " << cctv_data + 1 << std::endl;
        std::cout << "Group BJCD : " << pos_bjcds[cctv_data] << std::endl;
        for (int count = 0;count < multnum;count++) {                                                        // 5회 반복(각 그룹의 요소 추가)
            int cctv_id = pos_cctvs[cctv_data] + count;                                                      // cctv id
            std::string bjcd_id = pos_bjcds[cctv_data];                                                      // bjcd id
            cctvs.insert({ cctv_id , {cctv_id, bjcd_id} });                                                  // 더미 데이터로 추가
            cctv_group[pos_bjcds[cctv_data]].push_back({ cctv_id, bjcd_id });                                // 법정동 코드를 기준으로 그룹 생성
        }
        std::cout << "남아있는 CCTV : " << size << std::endl;
        std::cout << "생성할 CCTV : " << multnum << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        size -= multnum;
    }
    std::cout << "=============================================================================================" << std::endl;
    std::cout << "생성된 CCTV 그룹 수 " << cctv_group.size() << std::endl;
    std::cout << "생성된 CCTV 수 : " << cctvs.size() << std::endl;
    std::cout << "=============================================================================================" << std::endl;
    srand(time(NULL));
    //CCTV 리스크 모음 생성 및 리스크 CCTV 그룹 생성
    for (int risk_cctv = 0; risk_cctv < cctvs.size();risk_cctv++) {                                         //cctvs의 크기만큼 risk_cctv 생성
        int cctv_id = cctvs[pos_cctvs[risk_cctv / multnum] + risk_cctv % 5].id;                             //cctvs의 cctv_id 불러오기
        double rand_score = rand() % 100;                                                                     // 랜덤 점수 생성
        risk_cctvs.push_back({ cctv_id,rand_score });                                                       //리스크 CCTV 모음에 벡터 삽입
        risk_bjcd[pos_bjcds[risk_cctv / 5]].push_back({ cctv_id,rand_score });                              //리스크 그룹에 벡터 삽입
    }
    std::sort(risk_cctvs.begin(), risk_cctvs.end());

    //정렬이 된 CCTV 리스크 모음 출력
    for (int cctv_score = 0; cctv_score < risk_cctvs.size(); cctv_score++) {
        std::string bjcd = cctvs[risk_cctvs[cctv_score].cctv_id].bjcd;
        if (find(risk_check.begin(), risk_check.end(), bjcd) == risk_check.end()) {
            std::sort(risk_bjcd[bjcd].begin(), risk_bjcd[bjcd].end());
            risk_check.push_back(bjcd);
            std::cout << "BJCD : " << bjcd << std::endl;
            std::cout << "RISK CCTVS :" << std::endl;
            for (int roll = 0; roll < std::min(multnum, (int)risk_bjcd[bjcd].size()); roll++) {
                int cctv_id = risk_bjcd[bjcd][roll].cctv_id;
                auto it = std::find_if(risk_cctvs.begin(), risk_cctvs.end(), [&](const CCTV_RISK& r) {
                    return r.cctv_id == cctv_id;
                    });
                if (it != risk_cctvs.end()) {
                    std::cout << "CCTV ID : " << cctv_id << "/ SCORE : " << it->score << std::endl;
                }
            }
            std::cout << "-----------------------------------------------" << std::endl;
        }
    }
    std::cout << "=============================================================================================" << std::endl;

}