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
		 const std::string &locationCode,
		 double sampleRate)
: _id(networkCode + "." + stationCode)
, _lbs(networkCode, stationCode, locationCode, "LBS", sampleRate)
, _lbo(networkCode, stationCode, locationCode, "LBO", sampleRate)
, _lbp(networkCode, stationCode, locationCode, "LBP", sampleRate)
, _lbt(networkCode, stationCode, locationCode, "LBT", sampleRate)
, _lbr(networkCode, stationCode, locationCode, "LBR", sampleRate)
, _lbc(networkCode, stationCode, locationCode, "LBC", sampleRate)
, _lbe(networkCode, stationCode, locationCode, "LBE", sampleRate)
, _lbn(networkCode, stationCode, locationCode, "LBN", sampleRate)
, _lbz(networkCode, stationCode, locationCode, "LBZ", sampleRate)
, _lb1(networkCode, stationCode, locationCode, "LB1", sampleRate)
, _lb2(networkCode, stationCode, locationCode, "LB2", sampleRate)
, _lb3(networkCode, stationCode, locationCode, "LB3", sampleRate)
, _lb4(networkCode, stationCode, locationCode, "LB4", sampleRate)
, _lb5(networkCode, stationCode, locationCode, "LB5", sampleRate)
, _lb6(networkCode, stationCode, locationCode, "LB6", sampleRate) {
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Station::parse(const string &msg) {
	int yr, mo, dt, hh, mm, ss;
	int s, o, p, t, c;
	double r, e, n, z, ee, nn, zz, en, ez, nz;

	if ( sscanf(msg.c_str(),
		    "> %*s %4d%2d%2d%2d%2d%2d %d %d %d %d %lf %d"
		    "%lf %lf %lf %lf %lf %lf %lf %lf %lf",
		    &yr, &mo, &dt, &hh, &mm, &ss, &s, &o, &p, &t, &r, &c,
		    &e, &n, &z, &ee, &nn, &zz, &en, &ez, &nz) != 21 ) {
		SEISCOMP_ERROR("Invalid message: %s", msg.c_str());
		return;
	}

	Core::Time tm(yr, mo, dt, hh, mm, ss, 0);

	if ( ! tm.valid() ) {
		SEISCOMP_ERROR("Invalid time: %d%d%d%d%d%d", yr, mo, dt, hh, mm, ss);
		return;
	}

	_lbs.put(tm, s);
	_lbo.put(tm, o);
	_lbp.put(tm, p);
	_lbt.put(tm, t);
	_lbr.put(tm, r);
	_lbc.put(tm, c%100 + c/100%100 + c/10000%100 + c/1000000%100);
	_lbe.put(tm, e);
	_lbn.put(tm, n);
	_lbz.put(tm, z);
	_lb1.put(tm, ee);
	_lb2.put(tm, nn);
	_lb3.put(tm, zz);
	_lb4.put(tm, en);
	_lb5.put(tm, ez);
	_lb6.put(tm, nz);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


}
}
}
