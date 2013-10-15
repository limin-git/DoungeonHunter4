#ifndef SHAO_BING_H_INCLUDED
#define SHAO_BING_H_INCLUDED

#include "Character.h"


namespace DungeonHunter4
{

    // �ڱ�
    class ShaoBing : public Character
    {
    public:

        ShaoBing();

        void init();

        // �������ܣ�����
        void set_ji_xing();

        // �������ܣ���˪֮��
        void set_bing_shuang_zhi_jian();

        // �������ܣ�ӥ��
        void set_ying_yan();

        // ҩ��������ҩ��
        virtual void set_ji_su_yao_ji();

        // ҩ����ʿ���˺�
        virtual void set_shi_bing_shang_hai();

        static double ge_max_dps( size_t output_list_size = 10 );

    private:

        bool m_is_set_ying_yan; // �������ܣ�ӥ��
    };

} // namespace DungeonHunter4


#endif
