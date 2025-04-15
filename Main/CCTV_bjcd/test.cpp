#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <random>
#include <algorithm>

struct CCTV
{
    int id; // key
    std::string bjcd;

    CCTV() {}

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

int main()
{
    const int max_cctv_num = 100;
    std::map<int, CCTV> cctvs;
    std::set<CCTV_RISK> risk_cctvs;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 테스트 데이터셋 생성

    std::vector<int> pos_cctvs = { 5424, 5603, 71005, 71013, 4160, 9527, 8221, 8517, 80344, 3686, 6032, 9232, 1857, 35296, 48967, 49060, 47972,
    9985, 9919, 9947 };
    std::vector<std::string> pos_bjcds = { "4183041000", "4148037000", "4165035000", "4167031000", "4155035000", "4613014000", "4182031000", "4182031001"
        , "4136025600", "4163011400", "1120010800", "4719012300", "4122010600", "4793036000", "4167035000", "4182025000", "4372025000"
        , "9972025000", "9963034000", "9911011000" };

    std::random_device rd;  //시드값 획득
    std::mt19937 gen(rd()); //난수 생성 엔진 초기화
    std::uniform_int_distribution<> rand_score_dist(0, max_cctv_num); //난수 생성 범위 지정

    std::cout << "===================================================" << std::endl;
    std::cout << "테스트 더미 데이터 셋 생성" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "총 생성할 CCTV 그룹 수 : " << pos_bjcds.size() << std::endl;
    std::cout << "총 생성할 CCTV 수 : " << max_cctv_num << std::endl;
    std::cout << "===================================================" << std::endl;

    for (int i = 0; i < pos_cctvs.size(); i++)
    {
        int remain_cctv_num = max_cctv_num - cctvs.size();  //남아있는 CCTV 계산식
        int remain_pos_num = pos_cctvs.size() - i;          //남은 그룹 수 측정
        int rand_cctv_num_max = remain_cctv_num - remain_pos_num + 1; //남은 cctv 수에서 남은 그룹 수를 빼고 1을 더함으로써 각 그룹에 최소 1개의 cctv는 들어갈 수 있도록 함
        if (i < 10) rand_cctv_num_max /= 2;  // 데이터 균등하게 분배하기 위함

        std::uniform_int_distribution<> alloc_cctv_num_dist(1, rand_cctv_num_max);  //난수 생성 범위 지정
        int alloc_cctv_num = alloc_cctv_num_dist(gen);  //gen에 들어있는 난수 생성 엔진을 따라 난수 생성
        std::cout << "Group Index : " << i + 1 << std::endl << "Group BJCD : " << pos_bjcds[i] << std::endl;
        std::cout << "남아있는 CCTV : " << remain_cctv_num << std::endl;
        std::cout << "생성할 CCTV : " << alloc_cctv_num << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        for (int k = 0; k < alloc_cctv_num; k++)  //생성된 난수만큼 반복
        {
            int cctv_id = pos_cctvs[i] + k; // cctv 증강
            std::string bjcd = pos_bjcds[i];  //법정동 코드 선언
            double score = rand_score_dist(gen); //CCTV 위험도 난수 생성 엔진 따라 0 ~ 100 사이의 난수 생성
            cctvs[cctv_id] = CCTV(cctv_id, bjcd); //cctv 더미 데이터 생성
            risk_cctvs.insert(CCTV_RISK(cctv_id, score)); //cctv risk 더미 데이터 생성
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // BJCD 기반 침수 위험 CCTV 그룹화

    std::map<std::string, std::vector<CCTV_RISK>> grouped_risk_cctvs;
    std::vector<std::pair<std::string, double>> group_risk_order;

    for (auto risk_cctv : risk_cctvs)
    {
        int risk_cctv_id = risk_cctv.cctv_id;
        CCTV cctv = cctvs[risk_cctv_id];
        std::string bjcd = cctv.bjcd;

        if (grouped_risk_cctvs.find(bjcd) == grouped_risk_cctvs.end())
        {
            grouped_risk_cctvs[bjcd] = std::vector<CCTV_RISK>();
        }

        grouped_risk_cctvs[bjcd].push_back(risk_cctv);
    }

    for (auto [bjcd, risk_cctv_group] : grouped_risk_cctvs)
    {
        group_risk_order.push_back(std::make_pair(bjcd, risk_cctv_group[0].score));
    }

    std::sort(group_risk_order.begin(), group_risk_order.end(),
        [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
            return a.second > b.second;  // 내림차순
        });

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 그룹화된 침수 위험 CCTV 출력

    std::cout << "===================================================" << std::endl;
    std::cout << "생성된 CCTV 그룹 수 : " << grouped_risk_cctvs.size() << std::endl;
    std::cout << "생성된 CCTV 수 : " << cctvs.size() << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << "침수 위험 CCTV 법정동 코드 기반 그룹화 결과" << std::endl;
    std::cout << "===================================================" << std::endl;

    for (int i = 0; i < group_risk_order.size();i++)
    {
        std::string bjcd = group_risk_order[i].first;
        auto risk_cctv_group = grouped_risk_cctvs[bjcd];

        std::cout << "BJCD : " << bjcd << std::endl;
        std::cout << "RISK CCTVS : " << std::endl;

        for (int i = 0; i < risk_cctv_group.size(); i++)
        {
            std::cout << "CCTV ID : " << risk_cctv_group[i].cctv_id << " / SCORE : " << risk_cctv_group[i].score << std::endl;
        }

        std::cout << "--------------------------------------------------" << std::endl;
    }
    std::cout << "===================================================" << std::endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}