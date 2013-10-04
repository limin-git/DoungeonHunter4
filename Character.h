#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include "Store.h"


namespace DungeonHunter4
{

    class Character
    {
    public:

        Character();

        void init();

        // ����
        void set_wu_qi( const WuQi& wu_qi );

        // �籩����
        void set_feng_bao_fu_zhou( size_t feng_bao_fu_zhou );

        // ���ݷ���
        void set_min_jie_fu_zhou( size_t min_jie_fu_zhou );

        // �������
        void set_dong_cha_fu_zhou( size_t dong_cha_fu_zhou );

        // ��ָ
        void set_ring( const Ring& ring );

        // ���˹�ʽ
        double get_miao_shang();

        virtual double get_adjustment() { return 0; }

    public:

        double get_wu_qi_shang_hai();

    public:

        // ��ɫ����
        double m_miao_shang;

        // ��������
        double m_shang_hai;
        double m_gong_ji_su_du;                 // �����ٶ�
        double m_bao_ji_ji_lu;                  // ��������
        double m_bao_ji_jiang_li;               // �����˺�����
        // �ӡ��ӳ�
        double m_gong_ji_su_du_jia_cheng;       // % �����ٶ�
        double m_ji_chu_li_liang_jia;           // + ��������
        double m_yuan_su_shang_hai_jia_cheng;   // % Ԫ���˺����ױ���
        double m_bao_ji_ji_lu_jia;              // % ��������
        double m_bao_ji_jiang_li_jia;           // % �����˺�����
        double m_shang_hai_jia_cheng;           // % �˺�

        // ��Ʒ
        Ring m_ring;                            // ��ָ
        WuQi m_wu_qi;                           // ����
        size_t m_feng_bao_fu_zhou;              // �籩����
        size_t m_min_jie_fu_zhou;               // ���ݷ���
        size_t m_dong_cha_fu_zhou;              // �������
    };

} // namespace DungeonHunter4


#endif
