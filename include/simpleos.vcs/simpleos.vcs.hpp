#pragma once

#include <eosiolib/eosio.hpp>
#include<eosiolib/singleton.hpp>

using namespace eosio;
using namespace std;

namespace simpleos { 

	CONTRACT simpleos_vcs : public contract{
	public:

		simpleos_vcs(name recvr, name code, datastream<const char*> ds);

		ACTION newversion(string link, uint64_t checksum, string nversion );

	private:

    	TABLE info { 
        	string link;
        	uint64_t checksum;
        	string nversion;

        EOSLIB_SERIALIZE(info, (link)(checksum)(nversion))
    	};

    typedef singleton<name("version"), info> version_singleton;
    version_singleton _version;

	};
}//simpleos namespace

EOSIO_DISPATCH(simpleos::simpleos_vcs, (newversion))