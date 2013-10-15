// DungeonHunter4Character.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include "ShaoBing.h"
#include "ZhanDouDaShi.h"
#include "Store.h"


using namespace DungeonHunter4;

// ������ʥ���乭 ��ʥ���� ʳ��ħ���� ���򳤹�
// ��ָ���ƶ�ָ�� ����ָ�� �ҽ�֮�� ��ʯָ�� ������ Ī����˹�� Ů��֮��
//       ����֮�� ����֮�� �����ռ�֮�� ����ָ�� ����֮�� �������� �ۼ�ָ�� ʥ��֮��


// �ڱ�
void test_shao_bing()
{
    ShaoBing shao_bing;

    const WuQi& wu_qi = Store::instance().get_wu_qi( "ʥ���乭" );
    const Ring& ring = Store::instance().get_ring( "����֮��" );

    shao_bing.set_wu_qi( wu_qi );           // ����
    shao_bing.set_ring( ring );             // ��ָ
    shao_bing.set_feng_bao_fu_zhou( 5 );    // �籩����
    shao_bing.set_min_jie_fu_zhou( 10 );     // ���ݷ���
    //shao_bing.set_seng_lv_fu_zhou( 1 );     // ɮ�·���
    shao_bing.set_ji_xing();                // �������ܣ�����
    shao_bing.set_ying_yan();               // �������ܣ�ӥ��
    shao_bing.set_bing_shuang_zhi_jian();   // �������ܣ���˪֮��
    //shao_bing.set_shen_en_tian_ci();        // ��������������
    shao_bing.set_ji_su_yao_ji();           // ҩ��������ҩ��
    shao_bing.set_shi_bing_shang_hai();     // ҩ����ʿ���˺�

    double miao_shang = shao_bing.get_miao_shang();
    std::cout << "�ڱ���" << std::fixed <<  std::setprecision(2) << miao_shang << std::endl;

    ShaoBing::ge_max_dps();
}


// ս����ʦ
void test_zhan_dou_da_shi()
{

    ZhanDouDaShi zhan_dou_da_shi;

    const WuQi& wu_qi = Store::instance().get_wu_qi( "ʥ�೤��" );
    const Ring& ring = Store::instance().get_ring( "����֮��" );

    zhan_dou_da_shi.set_wu_qi( wu_qi );           // ����
    zhan_dou_da_shi.set_ring( ring );             // ��ָ
    zhan_dou_da_shi.set_feng_bao_fu_zhou( 4 );    // �籩����
    zhan_dou_da_shi.set_min_jie_fu_zhou( 6 );     // ���ݷ���
    zhan_dou_da_shi.set_dong_cha_fu_zhou( 5 );    // �������
    zhan_dou_da_shi.set_fen_nu();                 // �������ܣ���ŭ
    zhan_dou_da_shi.set_ji_shu_lao_shou();        // �������ܣ���������
    zhan_dou_da_shi.set_ji_su_yao_ji();           // ҩ��������ҩ��
    zhan_dou_da_shi.set_shi_bing_shang_hai();     // ҩ����ʿ���˺�

    double miao_shang = zhan_dou_da_shi.get_miao_shang();
    std::cout << "ս����ʦ��" << std::fixed <<  std::setprecision(2) << miao_shang << std::endl;

    ZhanDouDaShi::ge_max_dps();
}


int _tmain(int argc, _TCHAR* argv[])
{

    test_shao_bing();
    test_zhan_dou_da_shi();

	return 0;
}
