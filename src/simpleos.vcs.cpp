#include "simpleos_vcs/simpleos_vcs.hpp"

simpleos::simpleos_vcs::simpleos_vcs(name recvr, name code, datastream<const char*> ds) :
        contract(recvr, code, ds), _version(_self, _self.value) {}

void simpleos::simpleos_vcs::newversion(string link, uint64_t checksum, string nversion ){
	require_auth(_self);

	_version.set(info{link, checksum, nversion}, _self);
}