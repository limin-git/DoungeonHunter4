// DungeonHunter4Character.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>



struct WuQi
{
    WuQi( size_t wu_qi_shang_hai_min, size_t wu_qi_shang_hai_max )
    {
        m_wu_qi_shang_hai_min = wu_qi_shang_hai_min;
        m_wu_qi_shang_hai_max = wu_qi_shang_hai_max;
    }

    size_t m_wu_qi_shang_hai_min;
    size_t m_wu_qi_shang_hai_max;
};


struct Ring
{
    Ring( double bao_ji_ji_lu_jia = 0,             // ��������
          double bao_ji_jiang_li_jia = 0,          // ��������
          double ji_chu_shang_hai_jia = 0,         // �����˺�
          double yuan_su_shang_hai_jia_cheng = 0 ) // Ԫ���˺�
    {
        m_bao_ji_ji_lu_jia = bao_ji_ji_lu_jia;
        m_bao_ji_jiang_li_jia = bao_ji_jiang_li_jia;
        m_ji_chu_shang_hai_jia = ji_chu_shang_hai_jia;
        m_yuan_su_shang_hai_jia_cheng = yuan_su_shang_hai_jia_cheng;
    }

    double m_bao_ji_ji_lu_jia;
    double m_bao_ji_jiang_li_jia;
    double m_ji_chu_shang_hai_jia;
    double m_yuan_su_shang_hai_jia_cheng;
};



class DungeonHunter4Character
{
public:

    DungeonHunter4Character()
    {
        reset();
    }

    void reset()
    {
        // ��������
        m_ji_chu_shang_hai = 0;
        m_miao_shang = 0;

        // ����
        m_wu_qi_shang_hai_min = 0;
        m_wu_qi_shang_hai_max = 0;
        m_gong_ji_su_du = 0;
        m_bao_ji_ji_lu = 0.05;
        m_bao_ji_jiang_li = 0.5;

        // ����
        m_feng_bao_fu_zhou = 0;
        m_min_jie_fu_zhou = 0;
        m_dong_cha_fu_zhou = 0;

        // ���Լӳ�
        m_gong_ji_su_du_jia_cheng = 0;
        m_ji_chu_shang_hai_jia = 0;
        m_ji_chu_shang_hai_jia_cheng = 0;
        m_yuan_su_shang_hai_jia_cheng = 0;
        m_bao_ji_ji_lu_jia = 0;
        m_bao_ji_jiang_li_jia = 0;
        m_shang_hai_jia_cheng = 0;

        // ΢��
        m_adjustment = 0;
    }

    // ����
    void set_wu_qi( const WuQi& wu_qi )
    {
        m_wu_qi_shang_hai_min = wu_qi.m_wu_qi_shang_hai_min;
        m_wu_qi_shang_hai_max = wu_qi.m_wu_qi_shang_hai_max;
    }

    // ����
    void set_wu_qi( double wu_qi_shang_hai_min, double wu_qi_shang_hai_max )
    {
        m_wu_qi_shang_hai_min = wu_qi_shang_hai_min;
        m_wu_qi_shang_hai_max = wu_qi_shang_hai_max;
    }

    // �籩����
    void set_feng_bao_fu_zhou( size_t feng_bao_fu_zhou )
    {
        m_feng_bao_fu_zhou = feng_bao_fu_zhou;
    }

    // ���ݷ���
    void set_min_jie_fu_zhou( size_t min_jie_fu_zhou )
    {
        m_min_jie_fu_zhou = min_jie_fu_zhou;
    }

    // �������
    void set_dong_cha_fu_zhou( size_t dong_cha_fu_zhou )
    {
        m_dong_cha_fu_zhou = dong_cha_fu_zhou;
    }

    void set_ring( const Ring& ring )
    {
        m_ji_chu_shang_hai_jia += ring.m_ji_chu_shang_hai_jia;
        m_yuan_su_shang_hai_jia_cheng += ring.m_yuan_su_shang_hai_jia_cheng;
        m_bao_ji_ji_lu_jia += ring.m_bao_ji_ji_lu_jia;
        m_bao_ji_jiang_li_jia += ring.m_bao_ji_jiang_li_jia;
    }

    double miao_shang_ji_suan_gong_shi()
    {
        // �����˺�
        double ji_chu_shang_hai = std::ceil( ( m_wu_qi_shang_hai_min + m_wu_qi_shang_hai_max ) / 2.0 );
        m_ji_chu_shang_hai = ji_chu_shang_hai;
        m_ji_chu_shang_hai += m_ji_chu_shang_hai_jia; // ��������
        m_ji_chu_shang_hai += ji_chu_shang_hai * m_feng_bao_fu_zhou * 0.24; // �籩����
        m_ji_chu_shang_hai += ji_chu_shang_hai * m_ji_chu_shang_hai_jia_cheng; // ʿ���˺�
        m_ji_chu_shang_hai += ji_chu_shang_hai * m_yuan_su_shang_hai_jia_cheng;

        // ��������
        m_bao_ji_ji_lu += m_bao_ji_ji_lu_jia;
        m_bao_ji_ji_lu += m_dong_cha_fu_zhou * 0.1; // �������

        // ��������
        m_bao_ji_jiang_li += m_bao_ji_jiang_li_jia;
        m_bao_ji_jiang_li += m_min_jie_fu_zhou * 1.0; // ���ݷ���

        // �����˺�
        double bao_ji_shang_hai = m_ji_chu_shang_hai * ( 1.0 + m_bao_ji_jiang_li ) * m_bao_ji_ji_lu;

        // ��ͨ�˺�
        double pu_tong_shang_hai = 0;

        if ( m_bao_ji_ji_lu < 1 )
        {
            pu_tong_shang_hai = m_ji_chu_shang_hai * ( 1.0 - m_bao_ji_ji_lu );
        }
        
        // ƽ���˺�
        double ping_jun_shang_hai = bao_ji_shang_hai + pu_tong_shang_hai;

        // �˺�
        double shang_hai = ping_jun_shang_hai * ( 1 + m_shang_hai_jia_cheng );

        // ����
        m_miao_shang = shang_hai * m_gong_ji_su_du;

        return m_miao_shang + m_adjustment;
    }

public:

    double get_wu_qi_shang_hai()
    {
        return std::ceil( ( m_wu_qi_shang_hai_min + m_wu_qi_shang_hai_max ) / 2.0 );
    }

public:

    // ��������
    double m_ji_chu_shang_hai;
    double m_miao_shang;

    // ����
    double m_wu_qi_shang_hai_min;
    double m_wu_qi_shang_hai_max;
    double m_gong_ji_su_du;
    double m_bao_ji_ji_lu;
    double m_bao_ji_jiang_li;

    // ����
    size_t m_feng_bao_fu_zhou;
    size_t m_min_jie_fu_zhou;
    size_t m_dong_cha_fu_zhou;

    // ���Լӳ�
    double m_gong_ji_su_du_jia_cheng;
    double m_ji_chu_shang_hai_jia;
    double m_ji_chu_shang_hai_jia_cheng;
    double m_yuan_su_shang_hai_jia_cheng;
    double m_bao_ji_ji_lu_jia;
    double m_bao_ji_jiang_li_jia;
    double m_shang_hai_jia_cheng;

    // ΢��
    double m_adjustment;
};



class ShaoBing : public DungeonHunter4Character
{
public:

    ShaoBing()
    {
        m_gong_ji_su_du = 2;
    }

    void reset()
    {
        DungeonHunter4Character::reset();
        m_gong_ji_su_du = 2;
    }

    void set_ring( const Ring& ring )
    {
        m_ji_chu_shang_hai_jia += ring.m_ji_chu_shang_hai_jia;
        m_yuan_su_shang_hai_jia_cheng += ring.m_yuan_su_shang_hai_jia_cheng;
        m_bao_ji_ji_lu_jia += ring.m_bao_ji_ji_lu_jia;
        m_bao_ji_jiang_li_jia += ring.m_bao_ji_jiang_li_jia;

        m_adjustment -= get_wu_qi_shang_hai() * 0.1 * ring.m_yuan_su_shang_hai_jia_cheng;
    }

    // �������ܣ���˪֮��
    void set_bing_shuang_zhi_jian()
    {
        m_ji_chu_shang_hai_jia_cheng += 0.4;
    }

    // �������ܣ�ӥ��
    void set_ying_yan()
    {
        // �������ܣ�ӥ�ۼ���
        // - ƽ���˺��� 10%
        // - ƽ���˺� * �籩������� * �籩�����˺� * 10% 
        //m_bao_ji_ji_lu += 1.0;
        //m_bao_ji_jiang_li += 0.3;

        m_bao_ji_ji_lu_jia += 1.0;
        m_bao_ji_jiang_li_jia += 0.3;

        double shang_hai = get_wu_qi_shang_hai();
        m_adjustment -= shang_hai * 0.14;
        m_adjustment -= m_feng_bao_fu_zhou * 0.24 * shang_hai * 0.1;
    }


    static double caculate_max_dps()
    {
        double max_dps = 0;
        size_t feng_bao = 0;
        size_t min_jie = 0;

        // ʥ���乭
        WuQi sheng_jie_wan_gong( 72484, 85999 );

        ShaoBing shao_bing;

        for ( size_t i = 0; i < 15; ++i )
        {
            shao_bing.reset();
            shao_bing.set_wu_qi( sheng_jie_wan_gong );
            shao_bing.set_feng_bao_fu_zhou( i );
            shao_bing.set_min_jie_fu_zhou( 15 - i );
            shao_bing.set_bing_shuang_zhi_jian();   // �������ܣ���˪֮��
            shao_bing.set_ying_yan();               // �������ܣ�ӥ��

            double dps = shao_bing.miao_shang_ji_suan_gong_shi();

            if ( max_dps < dps )
            {
                max_dps = dps;
                feng_bao = i;
                min_jie = 15 - i;
            }
        }

        std::cout << "�籩���䣺" << feng_bao << std::endl;
        std::cout << "���ݷ��䣺" << min_jie << std::endl;
        std::cout << "�������ˣ�" << std::setprecision(20) << max_dps << std::endl;

        return max_dps;
    }
};


class ZhanDouDaShi : public DungeonHunter4Character
{
public:
    
    ZhanDouDaShi()
    {
        m_gong_ji_su_du = 1.579707703543008;
    }

    void reset()
    {
        DungeonHunter4Character::reset();
        m_gong_ji_su_du = 1.579707703543008;
    }

    // �������ܣ���ŭ
    void set_fen_nu()
    {
        m_shang_hai_jia_cheng += 0.4;
    }

    // �������ܣ���������
    void set_ji_shu_lao_shou()
    {
        m_bao_ji_ji_lu_jia += 0.3;
        m_bao_ji_jiang_li_jia += 1;
    }

    static double caculate_max_dps()
    {
        double max_dps = 0;
        size_t feng_bao = 0;
        size_t dong_cha = 0;
        size_t min_jie = 0;

        // ʥ�೤��
        WuQi sheng_jie_chang_jian( 113028, 136196 );

        ZhanDouDaShi zhan_dou_da_shi;

        for ( size_t i = 1; i <= 15; ++i ) // �籩
        {
            for ( size_t j = 1; j <= 15; ++j ) // ����
            {
                if ( i + j > 15 )
                {
                    continue;
                }

                for ( size_t k = 1; k <= 15; ++k ) // ����
                {
                    if ( i + j + k != 15 )
                    {
                        continue;
                    }

                    zhan_dou_da_shi.reset();
                    zhan_dou_da_shi.set_wu_qi( sheng_jie_chang_jian );
                    zhan_dou_da_shi.set_feng_bao_fu_zhou( i );
                    zhan_dou_da_shi.set_dong_cha_fu_zhou( j );
                    zhan_dou_da_shi.set_min_jie_fu_zhou( k );
                    zhan_dou_da_shi.set_fen_nu();           // �������ܣ���ŭ
                    zhan_dou_da_shi.set_ji_shu_lao_shou();  // �������ܣ���������

                    double dps = zhan_dou_da_shi.miao_shang_ji_suan_gong_shi();

                    if ( max_dps < dps )
                    {
                        max_dps = dps;
                        feng_bao = i;
                        dong_cha = j;
                        min_jie = k;
                    }
                }
            }
        }

        std::cout << "�籩���䣺" << feng_bao << std::endl;
        std::cout << "������䣺" << dong_cha << std::endl;
        std::cout << "���ݷ��䣺" << min_jie << std::endl;
        std::cout << "�������ˣ�" << std::setprecision(20) << max_dps << std::endl;

        return max_dps;
    }
};


int _tmain(int argc, _TCHAR* argv[])
{
    // ʥ���乭
    WuQi sheng_jie_wan_gong( 72484, 85999 );

    // ʳ��ħ
    WuQi shi_ren_mo( 288, 327 );

    // ��ʥ
    WuQi shen_sheng( 19209, 22685 );

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
    const Ring& jie_zhi = jing_shen_zhi_jie;

    DungeonHunter4Character hunter;

    hunter.set_wu_qi( wu_qi );           // ����
    //hunter.set_ring( jie_zhi );          // ��ָ
    hunter.set_feng_bao_fu_zhou( 4 );    // �籩����
    hunter.set_min_jie_fu_zhou( 6 );     // ���ݷ���
    hunter.set_dong_cha_fu_zhou( 5 );    // �������

    //std::cout <<  std::setprecision(20) << hunter.miao_shang_ji_suan_gong_shi() << std::endl;


    ZhanDouDaShi::caculate_max_dps();

	return 0;
}

