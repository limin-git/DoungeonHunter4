#ifndef ZHAN_DOU_DA_SHI_H_INCLUDED
#define ZHAN_DOU_DA_SHI_H_INCLUDED

#include "Character.h"


namespace DungeonHunter4
{

    // ս����ʦ
    class ZhanDouDaShi : public Character
    {
    public:

        ZhanDouDaShi();

        void init();

        // �������ܣ���ŭ
        void set_fen_nu();

        // �������ܣ���������
        void set_ji_shu_lao_shou();

        static double ge_max_dps();
    };

} // namespace DungeonHunter4


#endif
