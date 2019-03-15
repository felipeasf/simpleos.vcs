#include <simpleos.vcs/simpleos.vcs.hpp>

simpleos::version_control_system::version_control_system(name recvr, name code,
    datastream<const char*> ds) : contract(recvr, code, ds) {}

void simpleos::version_control_system::newversion(string link, checksum256 checksum,
    string version_number) {
    require_auth(_self);

    version_info_singl data(_self, _self.value);
    data.set(version_info{link, checksum, version_number}, _self);
}

EOSIO_DISPATCH(simpleos::version_control_system, (newversion))
