#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <cmath>
#include <set>


namespace DungeonHunter4
{
    
    struct WuQi
    {
        WuQi( double shang_hai_min = 0, double shang_hai_max = 0 )
        {
            m_shang_hai_min = shang_hai_min;
            m_shang_hai_max = shang_hai_max;
        }

        double get_shang_hai()
        {
            return std::ceil( ( m_shang_hai_min + m_shang_hai_max ) / 2.0 );
        }

        double m_shang_hai_min;
        double m_shang_hai_max;
    };


    struct Ring
    {
        Ring( size_t level = 0,
              const std::string& name = "",
              double bao_ji_ji_lv_jia = 0,             // ±©»÷¼¸ÂÊ
              double bao_ji_jiang_li_jia = 0,          // ±©»÷½±Àø
              double ji_chu_li_liang_jia = 0,          // »ù´¡ÉËº¦
              double yuan_su_shang_hai_jia_cheng = 0,  // ÔªËØÉËº¦¼Ó³É
              double shang_hai_jia_cheng = 0 )         // ÉËº¦¼Ó³É
        {
            m_level = level;
            m_name = name;

            m_bao_ji_ji_lv_jia = bao_ji_ji_lv_jia;
            m_bao_ji_jiang_li_jia = bao_ji_jiang_li_jia;
            m_ji_chu_li_liang_jia = ji_chu_li_liang_jia;
            m_yuan_su_shang_hai_jia_cheng = yuan_su_shang_hai_jia_cheng;
            m_shang_hai_jia_cheng = shang_hai_jia_cheng;
        }

        const bool operator<( const Ring& rhs ) const
        {
            return m_level < rhs.m_level;
        }

        size_t m_level;
        std::string m_name;

        double m_bao_ji_ji_lv_jia;
        double m_bao_ji_jiang_li_jia;
        double m_ji_chu_li_liang_jia;
        double m_yuan_su_shang_hai_jia_cheng;
        double m_shang_hai_jia_cheng;
    };

    typedef std::set<Ring> Rings;


    class Store
    {
    public:

        static Store& instance();

        const WuQi& get_wu_qi( const std::string& wu_qi_name );
        const Ring& get_ring( const std::string& name );

        std::map<std::string, WuQi*>& get_all_wu_qi();
        Rings& get_all_rings();

    private:

        Store();

        void build_wu_qi();
        void build_ring();

    private:

        std::map<std::string, WuQi*> m_wu_qi_map;
        Rings m_rings;
    };

} // DungeonHunter4


#endif
