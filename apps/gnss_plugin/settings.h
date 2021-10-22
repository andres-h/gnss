/***************************************************************************
 * (C) 2020 Helmholtz-Zentrum Potsdam - Deutsches GeoForschungsZentrum GFZ *
 * All rights reserved.                                                    *
 *                                                                         *
 * This file may be used under the terms of the GNU Affero                 *
 * Public License version 3.0 as published by the Free Software Foundation *
 * and appearing in the file LICENSE included in the packaging of this     *
 * file. Please review the following information to ensure the GNU Affero  *
 * Public License version 3.0 requirements will be met:                    *
 * https://www.gnu.org/licenses/agpl-3.0.html.                             *
 ***************************************************************************/

#ifndef SEISCOMP_APPS_GNSSPLUGIN_SETTINGS_H__
#define SEISCOMP_APPS_GNSSPLUGIN_SETTINGS_H__

#include <seiscomp/system/application.h>


namespace Seiscomp {
namespace Applications {
namespace GNSSPlugin {


// Define default configuration
struct Settings : System::Application::AbstractSettings {
	Settings(): udpport(9999) {
	}

	int udpport;

	virtual void accept(System::Application::SettingsLinker &linker) {
		linker
		& cfg(udpport, "udpport")
		& cli(udpport, "Server", "udpport",
		      "UDP port for receiving GNSS data packets",
		      true);
	}
};


extern Settings global;


}
}
}


#endif
