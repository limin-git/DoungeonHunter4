#include "stdafx.h"
#include "Character.h"


namespace DungeonHunter4
{

    Character::Character()
    {
        init();
    }


    void Character::init()
    {
        // ��ɫ����
        m_miao_shang = 0;

        // ��������
        m_shang_hai = 0;                     // �˺�
        m_gong_ji_su_du = 0;                 // �����ٶ�
        m_bao_ji_ji_lv = 0.05;               // ��������
        m_bao_ji_jiang_li = 0.5;             // �����˺�����
        m_gong_ji_su_du_jia_cheng = 0;       // +% �����ٶ�
        m_ji_chu_li_liang_jia = 0;           // +  ��������
        m_yuan_su_shang_hai_jia_cheng = 0;   // +% Ԫ���˺����ױ���
        m_bao_ji_ji_lv_jia = 0;              // +% ��������
        m_bao_ji_jiang_li_jia = 0;           // +% �����˺�����
        m_shang_hai_jia_cheng = 0;           // +% �˺�

        // ��Ʒ
        Ring m_ring = Ring();                // ��ָ
        m_feng_bao_fu_zhou = 0;              // �籩����
        m_min_jie_fu_zhou = 0;               // ���ݷ���
        m_dong_cha_fu_zhou = 0;              // �������
        m_seng_lv_fu_zhou = 0;               // ɮ�·���
    }


    // ����
    void Character::set_wu_qi( const WuQi& wu_qi )
    {
        m_wu_qi = wu_qi;
    }


    // �籩����
    void Character::set_feng_bao_fu_zhou( size_t feng_bao_fu_zhou )
    {
        m_feng_bao_fu_zhou = feng_bao_fu_zhou;
    }


    // ���ݷ���
    void Character::set_min_jie_fu_zhou( size_t min_jie_fu_zhou )
    {
        m_min_jie_fu_zhou = min_jie_fu_zhou;
    }


    // �������
    void Character::set_dong_cha_fu_zhou( size_t dong_cha_fu_zhou )
    {
        m_dong_cha_fu_zhou = dong_cha_fu_zhou;
    }

    // ɮ�·���
    void Character::set_seng_lv_fu_zhou( size_t seng_lv_fu_zhou )
    {
        m_seng_lv_fu_zhou = seng_lv_fu_zhou;
    }

    void Character::set_ring( const Ring& ring )
    {
        m_ji_chu_li_liang_jia           += ring.m_ji_chu_li_liang_jia;
        m_yuan_su_shang_hai_jia_cheng   += ring.m_yuan_su_shang_hai_jia_cheng;
        m_bao_ji_ji_lv_jia              += ring.m_bao_ji_ji_lv_jia;
        m_bao_ji_jiang_li_jia           += ring.m_bao_ji_jiang_li_jia;
        m_shang_hai_jia_cheng           += ring.m_shang_hai_jia_cheng;

        m_ring = ring;
    }


    double Character::get_miao_shang()
    {
        // �����˺�
        double ji_chu_shang_hai = get_wu_qi_shang_hai() + m_ji_chu_li_liang_jia;
        m_shang_hai = ji_chu_shang_hai;
        m_shang_hai += ji_chu_shang_hai * m_feng_bao_fu_zhou * 0.24;     // �籩����
        m_shang_hai += ji_chu_shang_hai * m_yuan_su_shang_hai_jia_cheng; // % Ԫ���˺�

        // �����ٶ�
        m_gong_ji_su_du *= ( 1 + m_gong_ji_su_du_jia_cheng + m_seng_lv_fu_zhou * 0.17 ); // ɮ�·���

        // ��������
        m_bao_ji_ji_lv += m_bao_ji_ji_lv_jia;
        m_bao_ji_ji_lv += m_dong_cha_fu_zhou * 0.1; // �������

        // �����˺�����
        m_bao_ji_jiang_li += m_bao_ji_jiang_li_jia;
        m_bao_ji_jiang_li += m_min_jie_fu_zhou * 1.0; // ���ݷ���

        // �����˺�
        double bao_ji_shang_hai = m_shang_hai * ( 1 + m_bao_ji_jiang_li ) * m_bao_ji_ji_lv;

        // ��ͨ�˺�
        double pu_tong_shang_hai = 0;

        if ( m_bao_ji_ji_lv < 1 )
        {
            pu_tong_shang_hai = m_shang_hai * ( 1 - m_bao_ji_ji_lv );
        }

        // ƽ���˺�
        double ping_jun_shang_hai = bao_ji_shang_hai + pu_tong_shang_hai;

        // ����
        m_miao_shang = ping_jun_shang_hai * m_gong_ji_su_du;

        // ΢��
        m_miao_shang += get_adjustment();

        m_miao_shang *= ( 1 + m_shang_hai_jia_cheng ); // % �˺�

        return m_miao_shang;
    }


    double Character::get_wu_qi_shang_hai()
    {
        return m_wu_qi.get_shang_hai();
    }

} // DungeonHunter4
