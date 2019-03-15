#include <simpleos.vcs/simpleos.vcs.hpp>

simpleos::version_control_system::version_control_system(name recvr, name code,
    datastream<const char*> ds) : contract(recvr, code, ds) {}

void simpleos::version_control_system::newversion(string link, checksum256 checksum,
    string version_number) {
    require_auth(_self);

    version_info_singl data(_self, _self.value);

    version_info new_version_info = data.exists() ? data.get() : version_info{};
    new_version_info.link = link;
    new_version_info.checksum = checksum;
    new_version_info.version_number = version_number;

    data.set(new_version_info, _self);
}

EOSIO_DISPATCH(simpleos::version_control_system, (newversion))
