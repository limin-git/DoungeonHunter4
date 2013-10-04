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

        // 武器
        void set_wu_qi( const WuQi& wu_qi );

        // 风暴符咒
        void set_feng_bao_fu_zhou( size_t feng_bao_fu_zhou );

        // 敏捷符咒
        void set_min_jie_fu_zhou( size_t min_jie_fu_zhou );

        // 洞察符咒
        void set_dong_cha_fu_zhou( size_t dong_cha_fu_zhou );

        // 戒指
        void set_ring( const Ring& ring );

        // 秒伤公式
        double get_miao_shang();

        virtual double get_adjustment() { return 0; }

    public:

        double get_wu_qi_shang_hai();

    public:

        // 角色数据
        double m_miao_shang;

        // 攻击数据
        double m_shang_hai;
        double m_gong_ji_su_du;                 // 攻击速度
        double m_bao_ji_ji_lu;                  // 暴击几率
        double m_bao_ji_jiang_li;               // 暴击伤害奖励
        // 加、加成
        double m_gong_ji_su_du_jia_cheng;       // % 攻击速度
        double m_ji_chu_li_liang_jia;           // + 基础力量
        double m_yuan_su_shang_hai_jia_cheng;   // % 元素伤害（雷冰）
        double m_bao_ji_ji_lu_jia;              // % 暴击几率
        double m_bao_ji_jiang_li_jia;           // % 暴击伤害奖励
        double m_shang_hai_jia_cheng;           // % 伤害

        // 物品
        Ring m_ring;                            // 戒指
        WuQi m_wu_qi;                           // 武器
        size_t m_feng_bao_fu_zhou;              // 风暴符咒
        size_t m_min_jie_fu_zhou;               // 敏捷符咒
        size_t m_dong_cha_fu_zhou;              // 洞察符咒
    };

} // namespace DungeonHunter4


#endif
