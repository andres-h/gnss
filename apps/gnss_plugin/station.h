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

#ifndef SEISCOMP_APPS_GNSSPLUGIN_STATION_H__
#define SEISCOMP_APPS_GNSSPLUGIN_STATION_H__

#include <string>
#include <seiscomp/core/baseobject.h>

#include "station.h"
#include "channel.h"


namespace Seiscomp {
namespace Applications {
namespace GNSSPlugin {

DEFINE_SMARTPOINTER(Station);
class Station : public Core::BaseObject {
	public:
		Station(const std::string &networkCode,
			const std::string &stationCode,
		       	double samprate);

		void parse(const std::string &msg);

	private:
		const std::string _id;
		Channel<double> _lbx;
		Channel<double> _lby;
		Channel<double> _lbz;
};


}
}
}


#endif
