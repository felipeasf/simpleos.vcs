#pragma once

#include <eosiolib/eosio.hpp>
#include <eosiolib/singleton.hpp>

using namespace eosio;
using namespace std;

namespace simpleos {
    struct [[eosio::table("version.info"), eosio::contract("simpleos.vcs")]] version_info {
        string link;
        checksum256 checksum;
        string version_number;

        EOSLIB_SERIALIZE(version_info, (link)(checksum)(version_number))
    };
    typedef singleton<name("version.info"), version_info> version_info_singl;

    class [[eosio::contract("simpleos.vcs")]] version_control_system : public contract {
        public:
            version_control_system(name recvr, name code, datastream<const char*> ds);

            [[eosio::action("newversion")]]
            void newversion(string link, checksum256 checksum, string version_number);
    };
}//simpleos namespace
