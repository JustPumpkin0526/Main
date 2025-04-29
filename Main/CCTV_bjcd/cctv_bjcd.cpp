#include "cctv_bjcd.h"

//직접 제작한 코드

//struct CCTV
//{
//    int id; // key
//    std::string bjcd;
//
//    CCTV() : id(0), bjcd("") {}
//
//    CCTV(int id, std::string bjcd)
//    {
//        this->id = id;
//        this->bjcd = bjcd;
//    }
//};
//
//struct CCTV_RISK
//{
//    int cctv_id;
//    double score;
//
//    bool operator<(const CCTV_RISK& other) const {
//        if (score == other.score)
//            return cctv_id < other.cctv_id;
//        return score > other.score;
//    };
//};
//
//void cctv_bjcd()
//{
//    std::cout << "=============================================================================================" << std::endl;
//    std::cout << "테스트 더미 데이터 셋 생성" << std::endl;
//    std::cout << "------------------------------------------------" << std::endl;
//
//    std::map<std::string, std::vector<CCTV>> cctv_group;                                                                                          //cctv의 그룹
//    std::map<int, CCTV> cctvs;                                                                                                                   //cctv 더미 데이터 모음
//    std::vector<CCTV_RISK> risk_cctvs;                                                                                                          // cctv 위험도 측정
//    std::map<std::string, std::vector<CCTV_RISK>> risk_bjcd;                                                                                    //cctv 위험도 bjcd 그룹
//    std::vector<std::string> risk_check;                                                                                                      // 중복 확인
//    double rand_score;                                                                                                                       // 스코어 랜덤 생성
//    int multnum = 5;                                                                                                                        // 곱할 숫자 5로 지정함
//    std::vector<int> pos_cctvs = { 5424, 5603, 71005, 71013, 4160, 9527, 3171, 8517, 80344, 3686, 6032, 9232, 1857, 35296, 48967, 49060, 47972,
//    9985, 9919, 9947 };                                                                                                                   //cctv id 모음
//    std::vector<std::string> pos_bjcds = { "4183041000", "4148037000", "4165035000", "4167031000", "4155035000", "4613014000", "4211034000", "4182031000"
//        , "4136025600", "4163011400", "1120010800", "4719012300", "4122010600", "4793036000", "4167035000", "4182025000", "4372025000"  //법정동 코드 모음
//        , "9972025000", "9963034000", "9911011000" };
//
//    std::cout << "총 생성할 CCTV 그룹 수 : " << pos_bjcds.size() << std::endl;
//    std::cout << "총 생성할 CCTV 수 : " << pos_cctvs.size() * multnum << std::endl;
//    std::cout << "=============================================================================================" << std::endl;
//    //cctv 데이터 모음 생성 및 그룹화 진행
//    int size = pos_cctvs.size() * multnum;                                                                   //그룹 사이즈
//    for (int cctv_data = 0; cctv_data < pos_cctvs.size(); cctv_data++) {                                     //cctvid 모음의 크기 만큼 반복 (20회 반복)
//        std::cout << "Group Index : " << cctv_data + 1 << std::endl;
//        std::cout << "Group BJCD : " << pos_bjcds[cctv_data] << std::endl;
//        for (int count = 0;count < multnum;count++) {                                                        // 5회 반복(각 그룹의 요소 추가)
//            int cctv_id = pos_cctvs[cctv_data] + count;                                                      // cctv id
//            std::string bjcd_id = pos_bjcds[cctv_data];                                                      // bjcd id
//            cctvs.insert({ cctv_id , {cctv_id, bjcd_id} });                                                  // 더미 데이터로 추가
//            cctv_group[pos_bjcds[cctv_data]].push_back({ cctv_id, bjcd_id });                                // 법정동 코드를 기준으로 그룹 생성
//        }
//        std::cout << "남아있는 CCTV : " << size << std::endl;
//        std::cout << "생성할 CCTV : " << multnum << std::endl;
//        std::cout << "-----------------------------------------------" << std::endl;
//        size -= multnum;
//    }
//    std::cout << "=============================================================================================" << std::endl;
//    std::cout << "생성된 CCTV 그룹 수 " << cctv_group.size() << std::endl;
//    std::cout << "생성된 CCTV 수 : " << cctvs.size() << std::endl;
//    std::cout << "=============================================================================================" << std::endl;
//    srand(time(NULL));
//    //CCTV 리스크 모음 생성 및 리스크 CCTV 그룹 생성
//    for (int risk_cctv = 0; risk_cctv < cctvs.size();risk_cctv++) {                                         //cctvs의 크기만큼 risk_cctv 생성
//        int cctv_id = cctvs[pos_cctvs[risk_cctv / multnum] + risk_cctv % 5].id;                             //cctvs의 cctv_id 불러오기
//        double rand_score = rand() % 100;                                                                     // 랜덤 점수 생성
//        risk_cctvs.push_back({ cctv_id,rand_score });                                                       //리스크 CCTV 모음에 벡터 삽입
//        risk_bjcd[pos_bjcds[risk_cctv / 5]].push_back({ cctv_id,rand_score });                              //리스크 그룹에 벡터 삽입
//    }
//    std::sort(risk_cctvs.begin(), risk_cctvs.end());
//
//    //정렬이 된 CCTV 리스크 모음 출력
//    for (int cctv_score = 0; cctv_score < risk_cctvs.size(); cctv_score++) {
//        std::string bjcd = cctvs[risk_cctvs[cctv_score].cctv_id].bjcd;
//        if (find(risk_check.begin(), risk_check.end(), bjcd) == risk_check.end()) {
//            std::sort(risk_bjcd[bjcd].begin(), risk_bjcd[bjcd].end());
//            risk_check.push_back(bjcd);
//            std::cout << "BJCD : " << bjcd << std::endl;
//            std::cout << "RISK CCTVS :" << std::endl;
//            for (int roll = 0; roll < std::min(multnum, (int)risk_bjcd[bjcd].size()); roll++) {
//                int cctv_id = risk_bjcd[bjcd][roll].cctv_id;
//                auto it = std::find_if(risk_cctvs.begin(), risk_cctvs.end(), [&](const CCTV_RISK& r) {
//                    return r.cctv_id == cctv_id;
//                    });
//                if (it != risk_cctvs.end()) {
//                    std::cout << "CCTV ID : " << cctv_id << "/ SCORE : " << it->score << std::endl;
//                }
//            }
//            std::cout << "-----------------------------------------------" << std::endl;
//        }
//    }
//    std::cout << "=============================================================================================" << std::endl;
//
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//개선된 코드

//cctv의 정보를 모은 구조체
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
//cctv의 위험도를 알 수 있는 구조체
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

void cctv_bjcd()
{
    const int max_cctv_num = 100;
    std::map<int, CCTV> cctvs;      //cctv id별로 나누기 위한 map 변수
    std::set<CCTV_RISK> risk_cctvs; //set을 사용해 자동 정렬

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 테스트 데이터셋 생성

    std::vector<int> pos_cctvs = { 5424, 5603, 71005, 71013, 4160, 9527, 8221, 8517, 80344, 3686, 6032, 9232, 1857, 35296, 48967, 49060, 47972,
    9985, 9919, 9947 };
    std::vector<std::string> pos_bjcds = { "4183041000", "4148037000", "4165035000", "4167031000", "4155035000", "4613014000", "4182031000", "4182031001"
        , "4136025600", "4163011400", "1120010800", "4719012300", "4122010600", "4793036000", "4167035000", "4182025000", "4372025000"
        , "9972025000", "9963034000", "9911011000" };

    std::random_device rd;                                              //시드값 획득
    std::mt19937 gen(rd());                                             //난수 생성 엔진 초기화
    std::uniform_int_distribution<> rand_score_dist(0, max_cctv_num);   //난수 생성 범위 지정

    std::cout << "===================================================" << std::endl;
    std::cout << "테스트 더미 데이터 셋 생성" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "총 생성할 CCTV 그룹 수 : " << pos_bjcds.size() << std::endl;
    std::cout << "총 생성할 CCTV 수 : " << max_cctv_num << std::endl;
    std::cout << "===================================================" << std::endl;

    for (int i = 0; i < pos_cctvs.size(); i++)              //더미 데이터 생성 코드
    {
        int remain_cctv_num = max_cctv_num - cctvs.size();  //남은 cctv의 수 계산식
        int remain_pos_num = pos_cctvs.size() - i;          //남은 그룹 수 측정
        int rand_cctv_num_max = remain_cctv_num - remain_pos_num + 1; //생성할 cctv의 최대 갯수 (남은 cctv의 수에서 남은 그룹 수를 빼고 1을 더함으로써 각 그룹에 최소 1개의 cctv는 들어갈 수 있도록 함)
        if (i < 10) rand_cctv_num_max /= 2;                 // 데이터 균등하게 분배하기 위함 (한 그룹의 과도하게 쏠리는 문제 방지)

        std::uniform_int_distribution<> alloc_cctv_num_dist(1, rand_cctv_num_max);  //난수 생성 범위 지정
        int alloc_cctv_num = alloc_cctv_num_dist(gen);      //gen에 들어있는 난수 생성 엔진을 따라 난수 생성
        std::cout << "Group Index : " << i + 1 << std::endl << "Group BJCD : " << pos_bjcds[i] << std::endl;
        std::cout << "남아있는 CCTV : " << remain_cctv_num << std::endl;
        std::cout << "생성할 CCTV : " << alloc_cctv_num << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        for (int k = 0; k < alloc_cctv_num; k++)    //난수만큼 cctvs/risk_cctvs 더미 데이터 생성
        {
            int cctv_id = pos_cctvs[i] + k;         //cctv 증강
            std::string bjcd = pos_bjcds[i];        //현재 법정동 코드 확인
            double score = rand_score_dist(gen);    //CCTV 위험도 생성 (난수 생성 엔진 따라 0 ~ 100 사이의 난수 생성)
            //std::cout << cctv_id << std::endl;
            cctvs[cctv_id] = CCTV(cctv_id, bjcd);          //cctvs 더미 데이터 생성 
            risk_cctvs.insert(CCTV_RISK(cctv_id, score));  //risk_cctvs 더미 데이터 생성
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // BJCD 기반 침수 위험 CCTV 그룹화

    std::map<std::string, std::vector<CCTV_RISK>> grouped_risk_cctvs;  //cctv 그룹화용 변수
    std::vector<std::pair<std::string, double>> group_risk_order;      //risk_cctvs의 정렬 그룹화용 변수
    //법정동 코드 별 grouped_risk_cctvs 초기화

    for (int i = 0;i < pos_bjcds.size(); i++) {
        grouped_risk_cctvs[pos_bjcds[i]] = std::vector<CCTV_RISK>();
    }

    for (auto risk_cctv : risk_cctvs)                                   //그룹을 만들기 위한 반복문 (risk_cctvs 속 모든 요소 가져옴)                           
    {
        int risk_cctv_id = risk_cctv.cctv_id;                           //set을 사용해 정렬된 risk_cctv의 cctv_id 저장
        CCTV cctv = cctvs[risk_cctv_id];                                //cctvs의 cctv_id에 해당하는 CCTV 구조체를 불러와 cctv에 저장
        std::string bjcd = cctv.bjcd;                                   //법정동 코드 저장

        //if (grouped_risk_cctvs.find(bjcd) == grouped_risk_cctvs.end())  //중복 거름망
        //{
        //    grouped_risk_cctvs[bjcd] = std::vector<CCTV_RISK>();        //key:value 초기화
        //}
        /*if (cctv.bjcd == "4165035000") {
            std::cout << cctv.bjcd << std::endl;
            std::cout << cctv.id << std::endl;
        }
        if (cctv.bjcd == "4167031000") {
            std::cout << cctv.bjcd << std::endl;
            std::cout << cctv.id << std::endl;
        }*/
        grouped_risk_cctvs[bjcd].push_back(risk_cctv);                  //법정동 코드를 기준으로 해당하는 법정동 코드를 가진 CCTV_RISK 값 추가
    }
    


    for (auto [bjcd, risk_cctv_group] : grouped_risk_cctvs)             // cctv 그룹 정렬을 위한 반복, grouped_risk_cctvs 속 모든 요소를 가져옴
    {
        group_risk_order.push_back(std::make_pair(bjcd, risk_cctv_group[0].score)); //정렬을 진행할 새로운 그룹에 값 추가
    }

    std::sort(group_risk_order.begin(), group_risk_order.end(),         // 정렬하는 코드, 람다를 사용해 내림차순으로 정렬을 하게 만듬
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

    for (int i = 0; i < group_risk_order.size();i++)                    //출력하기 위한 반복문
    {
        std::string bjcd = group_risk_order[i].first;                   //정렬 그룹의 key값인 bjcd를 받는 변수
        auto risk_cctv_group = grouped_risk_cctvs[bjcd];                //cctv 그룹의 bjcd에 해당하는 vector를 받는 변수

        std::cout << "BJCD : " << bjcd << std::endl;
        std::cout << "RISK CCTVS : " << std::endl;

        for (int i = 0; i < risk_cctv_group.size(); i++)                //법정동 코드를 기준으로 그룹화된 cctvid와 위험도를 정렬된 순서대로 출력하는 코드
        {
            std::cout << "CCTV ID : " << risk_cctv_group[i].cctv_id << " / SCORE : " << risk_cctv_group[i].score << std::endl;
        }

        std::cout << "--------------------------------------------------" << std::endl;
    }
    std::cout << "===================================================" << std::endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //문제점 (cctv_id가 71005, 71013 이렇게 적은 범위로 존재할 시 생성할 cctv가 많아지면 서로 범위를 침범해 출력이 꼬이게 된다.)
}