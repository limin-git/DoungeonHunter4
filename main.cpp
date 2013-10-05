// DungeonHunter4Character.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include "ShaoBing.h"
#include "ZhanDouDaShi.h"
#include "Store.h"


using namespace DungeonHunter4;


int _tmain(int argc, _TCHAR* argv[])
{
#if 1
    {
        // ս����ʦ

        ZhanDouDaShi zhan_dou_da_shi;

        const WuQi& wu_qi = Store::instance().get_wu_qi( "ʥ�೤��" );
        const Ring& ring = Store::instance().get_ring( "�ҽ�֮��" ); // �ҽ�֮�� ����֮�� 

        zhan_dou_da_shi.set_wu_qi( wu_qi );           // ����
        zhan_dou_da_shi.set_ring( ring );             // ��ָ
        zhan_dou_da_shi.set_feng_bao_fu_zhou( 4 );    // �籩����
        zhan_dou_da_shi.set_min_jie_fu_zhou( 6 );     // ���ݷ���
        zhan_dou_da_shi.set_dong_cha_fu_zhou( 5 );    // �������
        zhan_dou_da_shi.set_fen_nu();                 // �������ܣ���ŭ
        zhan_dou_da_shi.set_ji_shu_lao_shou();        // �������ܣ���������

        //std::cout <<  std::setprecision(20) << zhan_dou_da_shi.get_miao_shang() << std::endl;
        ZhanDouDaShi::ge_max_dps();
    }
#endif



#if 0
    {
        // �ڱ�
        ShaoBing shao_bing;

        const WuQi& wu_qi = Store::instance().get_wu_qi( "ʥ���乭" );      // ʥ���乭 ��ʥ���� ʳ��ħ���� ���򳤹� 
        const Ring& ring = Store::instance().get_ring( "����֮��" );  // ����ָ�� �ҽ�֮�� ��ʯָ�� ������ Ī����˹�� ����֮�� ����֮�� �����ռ�֮�� ����ָ�� ����֮�� �������� �ۼ�ָ�� ʥ��֮�� Ů��֮��

        shao_bing.set_wu_qi( wu_qi );           // ����
        shao_bing.set_ring( ring );          // ��ָ
        shao_bing.set_feng_bao_fu_zhou( 5 );    // �籩����
        shao_bing.set_min_jie_fu_zhou( 10 );     // ���ݷ���
        //shao_bing.set_ying_yan();               // �������ܣ�ӥ��
        shao_bing.set_bing_shuang_zhi_jian();   // �������ܣ���˪֮��

        std::cout <<  std::setprecision(20) << shao_bing.get_miao_shang() << std::endl;
        //ShaoBing::ge_max_dps();
    }
#endif


	return 0;
}








































#if 0

// ʥ���乭
WuQi sheng_jie_wan_gong( 72484, 85999 );

// ʳ��ħ
WuQi shi_ren_mo( 288, 327 );

// ��ʥ����
WuQi shen_sheng_chang_gong( 19209, 22685 );

// ʥ�೤��
WuQi sheng_jie_chang_jian( 113028, 136196 );

// ��ʥ��
WuQi shen_sheng_kuan_jian( 29636, 35593 );

// ʳ��ħ��
WuQi shi_ren_mo_da_jian( 406, 474 );

// ����֮��
Ring jing_shen_zhi_jie( 0, 0.8, 0, 0.2 );

// �ҽ�֮��
Ring hui_jin_zhi_jie( 0, 0, 0, 0.35 );

// ����
const WuQi& wu_qi = sheng_jie_chang_jian;

// ��ָ
const Ring& ring = jing_shen_zhi_jie;

DungeonHunter4Character hunter;

hunter.set_wu_qi( wu_qi );           // ����
//hunter.set_ring( ring );          // ��ָ
hunter.set_feng_bao_fu_zhou( 4 );    // �籩����
hunter.set_min_jie_fu_zhou( 6 );     // ���ݷ���
hunter.set_dong_cha_fu_zhou( 5 );    // �������

//std::cout <<  std::setprecision(20) << hunter.get_miao_shang() << std::endl;



#endif