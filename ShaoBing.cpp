#include "stdafx.h"
#include "ShaoBing.h"
#include "DpsConfiguration.h"


namespace DungeonHunter4
{

    ShaoBing::ShaoBing()
    {
        init();
    }


    void ShaoBing::init()
    {
        Character::init();

        m_gong_ji_su_du = 2;
        m_is_set_ying_yan = false;
    }


    // �������ܣ�����
    void ShaoBing::set_ji_xing()
    {
        m_gong_ji_su_du_jia_cheng += 0.5;
    }


    // �������ܣ���˪֮��
    void ShaoBing::set_bing_shuang_zhi_jian()
    {
        m_yuan_su_shang_hai_jia_cheng += 0.4;
    }


    // �������ܣ�ӥ��
    void ShaoBing::set_ying_yan()
    {
        // �������ܣ�ӥ�ۼ���
        // + 100% ��������
        // + 30% �����˺�����
        // - 10% �����˺�
        // - 10% �����˺� x Ԫ���˺�

        m_is_set_ying_yan = true;

        m_bao_ji_ji_lv_jia += 1;
        m_bao_ji_jiang_li_jia += 0.3;
    }


    // ҩ��������ҩ��
    void ShaoBing::set_ji_su_yao_ji()
    {
        m_gong_ji_su_du_jia_cheng += 0.5;
    }


    // ҩ����ʿ���˺�
    void ShaoBing::set_shi_bing_shang_hai()
    {
        m_shang_hai_jia_cheng += 1;
    }


    double ShaoBing::ge_max_dps( size_t output_list_size )
    {
        ShaoBing shao_bing;

        shao_bing.set_wu_qi( Store::instance().get_wu_qi( "ʥ���乭" ) );
        shao_bing.set_ji_xing();                // �������ܣ�����
        shao_bing.set_bing_shuang_zhi_jian();   // �������ܣ���˪֮��
        shao_bing.set_ying_yan();               // �������ܣ�ӥ��
        shao_bing.set_ji_su_yao_ji();           // ҩ��������ҩ��
        shao_bing.set_shi_bing_shang_hai();     // ҩ����ʿ���˺�

        DpsList dps_list;
        Character::get_dps_list( shao_bing, dps_list );

        for ( DpsList::iterator it = dps_list.begin(); it != dps_list.end() && 0 < output_list_size; ++it, --output_list_size )
        {
            it->output();
            std::cout << std::endl;
        }

        return dps_list.begin()->m_dps;
    }

} // namespace DungeonHunter4
