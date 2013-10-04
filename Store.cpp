#include "stdafx.h"
#include "Store.h"


namespace DungeonHunter4
{

    Store& Store::instance()
    {
        static Store store;
        return store;
    }


    const WuQi& Store::get_wu_qi( const std::string& wu_qi_name )
    {
        std::map<std::string, WuQi*>::iterator find_it = m_wu_qi_map.find( wu_qi_name );

        if ( find_it == m_wu_qi_map.end() )
        {
            assert( false );
        }

        return *(find_it->second);
    }


    const Ring& Store::get_ring( const std::string& ring_name )
    {
        std::map<std::string, Ring*>::iterator find_it = m_ring_map.find( ring_name );

        if ( find_it == m_ring_map.end() )
        {
            assert( false );
        }

        return *(find_it->second);
    }


    std::map<std::string, WuQi*>& Store::get_all_wu_qi()
    {
        return m_wu_qi_map;
    }


    std::map<std::string, Ring*>& Store::get_all_ring()
    {
        return m_ring_map;
    }


    void Store::build_wu_qi()
    {
        m_wu_qi_map[ "ʥ���乭" ]       = new WuQi( 72484, 85999 );
        m_wu_qi_map[ "ʳ��ħ����" ]     = new WuQi( 288, 327 );
        m_wu_qi_map[ "��ʥ����" ]       = new WuQi( 19209, 22685 );

        m_wu_qi_map[ "ʥ�೤��" ]       = new WuQi( 113028, 136196 );
        m_wu_qi_map[ "��ʥ��" ]       = new WuQi( 29636, 35593 );
        m_wu_qi_map[ "ʳ��ħ��" ]     = new WuQi( 406, 474 );
    }


    void Store::build_ring()
    {
#if 0
        Ring;
        double bao_ji_ji_lu_jia;             // ��������
        double bao_ji_jiang_li_jia;          // ��������
        double ji_chu_shang_hai_jia;         // �����˺�
        double yuan_su_shang_hai_jia_cheng;  // Ԫ���˺��ӳ�
        double ji_chu_shang_hai_jia_cheng;   // �˺��ӳ�
#endif
        m_ring_map[ "�ҽ�֮��" ]     = new Ring( 0,    0,    0,   0.35, 0.00 );
        m_ring_map[ "����ָ��" ]     = new Ring( 0,    0,    0,   0.11, 0.00 );
        m_ring_map[ "����֮��" ]     = new Ring( 0,    0,    0,   0.11, 0.00 );
        m_ring_map[ "��ʯָ��" ]     = new Ring( 0,    0,    0,   0.35, 0.00 );
        //m_ring_map[ "��ʯ��ָ" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "�ػ�" ]         = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "��������" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "����֮��" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        m_ring_map[ "������" ]       = new Ring( 0,    0,    0,   0.20, 0.00 );
        m_ring_map[ "Ī����˹��" ]   = new Ring( 0,    0,    0,   0.20, 0.00 );
        m_ring_map[ "����֮��" ]     = new Ring( 0,    0,    805, 0.20, 0.00 );
        m_ring_map[ "����֮��" ]     = new Ring( 0,    0.80, 0,   0.2,  0.00 );
        // m_ring_map[ "����ָ��" ]     = new Ring( 0,    0.70, 637, 0,    0.07 ); //TODO
        m_ring_map[ "����֮��" ]     = new Ring( 0,    0.70, 0,   0.07, 0.00 );
        m_ring_map[ "ʥ��֮��" ]     = new Ring( 0,    0,    0,   0,    0.07 );
        // m_ring_map[ "Ů��֮��" ]     = new Ring( 0,    0,    637, 0,    0.07 ); //TODO
        m_ring_map[ "�ۼ�ָ��" ]     = new Ring( 0,    0,    0,   0.16, 0.00 );
        m_ring_map[ "�ƶ�ָ��" ]     = new Ring( 0.06, 0,    0,   0,    0.06 );
        //m_ring_map[ "����ָ��" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "���֮��" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        m_ring_map[ "������ָ" ]     = new Ring( 0.05, 0.50, 0,   0,    0.00 );
        //m_ring_map[ "����ָ��" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "��ħ֮��" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        // m_ring_map[ "��������" ]     = new Ring( 0,    0,    380, 0,    0.05 ); //TODO
        //m_ring_map[ "�Ų�֮��" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "Ұ��֮��" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "������ֺ��" ]   = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "���֮��" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "�洫��ָ" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "���֮��" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "����ָ" ]       = new Ring( 0,    0,    0,   0,    0.00 );
        m_ring_map[ "�����ռ�֮��" ] = new Ring( 0,    0,    214, 0,    0.00 );
        //m_ring_map[ "" ]             = new Ring( 0,    0,    0,   0,    0.00 );
    }


    Store::Store()
    {
        build_wu_qi();
        build_ring();
    }

} // namespace DungeonHunter4
