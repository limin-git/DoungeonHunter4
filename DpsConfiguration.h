#ifndef DPS_CONFIGURATION_H_INCLUDED
#define DPS_CONFIGURATION_H_INCLUDED

#include <string>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <cassert>


namespace DungeonHunter4
{

    class DpsConfiguration
    {
    public:

        DpsConfiguration()
            : m_dps( 0 )
        {
        }

        void set_dps( double dps )
        {
            m_dps = dps;
        }

        void add_configuration( const std::string& fu_zhou, size_t number )
        {
            m_configuration.push_back( std::make_pair( fu_zhou, number ) );
        }

        void add_configuration( const std::string& ring )
        {
            m_configuration.push_back( std::make_pair( ring, -1 ) );
        }

        bool operator < ( const DpsConfiguration& rhs ) const
        {
            return m_dps > rhs.m_dps;
        }

        void output( std::ostream& os = std::cout ) const
        {
            assert( m_dps != 0 );

            for ( size_t i = 0; i < m_configuration.size(); ++i )
            {
                os << m_configuration[i].first;

                if ( m_configuration[i].second != -1 )
                {
                    os << "=" << m_configuration[i].second;
                }

                os << "£¬";
            }

            os << "ÃëÉË=" << std::fixed << std::setprecision(2) << m_dps;
        }

    public:

        double m_dps;
        std::vector< std::pair<std::string, int> > m_configuration;
    };

    typedef std::set<DpsConfiguration> DpsList;

} // namespace DungeonHunter4


#endif
