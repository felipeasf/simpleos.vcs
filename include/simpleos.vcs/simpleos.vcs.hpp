#pragma once

#include <eosiolib/eosio.hpp>
#include <eosiolib/singleton.hpp>

using namespace eosio;
using namespace std;

namespace simpleos {

    struct [[eosio::table("binary.info"), eosio::contract("simpleos.vcs")]] binary {

        checksum256 checksum;
        string binary_name;
        string binary_link;

        EOSLIB_SERIALIZE(binary, (checksum)(binary_name)(binary_link))
    };

    struct [[eosio::table("version.info"), eosio::contract("simpleos.vcs")]] version_info {
        string link;
        string version_number;
        vector<binary> binaries;

        EOSLIB_SERIALIZE(version_info, (link)(version_number)(binaries))
    };
    typedef singleton<name("version.info"), version_info> version_info_singl;

    class [[eosio::contract("simpleos.vcs")]] version_control_system : public contract {
        public:
            version_control_system(name recvr, name code, datastream<const char*> ds);

            [[eosio::action("newversion")]]
            void newversion(string link, string version_number, vector<binary> binaries);
    };
}//simpleos namespace
