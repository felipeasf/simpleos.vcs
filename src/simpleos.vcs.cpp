#include <simpleos.vcs/simpleos.vcs.hpp>

simpleos::version_control_system::version_control_system(name recvr, name code,
    datastream<const char*> ds) : contract(recvr, code, ds) {}

void simpleos::version_control_system::newversion(string link, string version_number, vector<binary> binaries) {
    require_auth(_self);

    version_info_singl data(_self, _self.value);

    data.set(version_info{link, version_number, binaries}, _self);
}

EOSIO_DISPATCH(simpleos::version_control_system, (newversion))
