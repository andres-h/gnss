/***************************************************************************
 * (C) 2021 Helmholtz-Zentrum Potsdam - Deutsches GeoForschungsZentrum GFZ *
 * All rights reserved.                                                    *
 *                                                                         *
 * This file may be used under the terms of the GNU Affero                 *
 * Public License version 3.0 as published by the Free Software Foundation *
 * and appearing in the file LICENSE included in the packaging of this     *
 * file. Please review the following information to ensure the GNU Affero  *
 * Public License version 3.0 requirements will be met:                    *
 * https://www.gnu.org/licenses/agpl-3.0.html.                             *
 ***************************************************************************/

#include <string>
#include <cstdio>

#define SEISCOMP_COMPONENT GNSS
#include <seiscomp/logging/log.h>

#include "station.h"


using namespace std;
using namespace Seiscomp;


namespace Seiscomp {
namespace Applications {
namespace GNSSPlugin {


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Station::Station(const std::string &networkCode,
		 const std::string &stationCode,
		 double samprate)
: _id(networkCode + "." + stationCode)
, _lbx(networkCode, stationCode, "00", "LBX", samprate)
, _lby(networkCode, stationCode, "00", "LBY", samprate)
, _lbz(networkCode, stationCode, "00", "LBZ", samprate) {
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Station::parse(const string &msg) {
	int y, m, d, hh, mm, ss;
	int a, b, c, dd, f;
	double e, lbx, lby, lbz;

	if ( sscanf(msg.c_str(), "> %*s %4d%2d%2d%2d%2d%2d %d %d %d %d %lf %d %lf %lf %lf",
		    &y, &m, &d, &hh, &mm, &ss, &a, &b, &c, &dd, &e, &f, &lbx, &lby, &lbz) != 15 ) {
		SEISCOMP_ERROR("Invalid message: %s", msg.c_str());
		return;
	}

	Core::Time t(y, m, d, hh, mm, ss, 0);

	if ( ! t.valid() ) {
		SEISCOMP_ERROR("Invalid time: %d%d%d%d%d%d", y, m, d, hh, mm, ss);
		return;
	}

	_lbx.put(t, lbx);
	_lby.put(t, lby);
	_lbz.put(t, lbz);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


}
}
}
