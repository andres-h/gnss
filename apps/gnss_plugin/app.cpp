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

#define SEISCOMP_COMPONENT GNSS
#include <seiscomp/logging/log.h>

#include "app.h"
#include "settings.h"


using namespace std;
using namespace Seiscomp;


namespace Seiscomp {
namespace Applications {
namespace GNSSPlugin {


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Application::Application(int argc, char** argv)
: Client::Application(argc, argv) {
	setMessagingEnabled(false);
	setDatabaseEnabled(false, false);
	setLoadConfigModuleEnabled(false);
	setLoadStationsEnabled(false);
	bindSettings(&global);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Application::init() {
	if ( !Client::Application::init() )
		return false;

	// read config here
	_client.addStation("MRCO", "GE", "MARCO", 1.0);
	_client.addStation("CAFE", "IV", "CAFE", 1.0);

	return true;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool Application::run() {
	SEISCOMP_INFO("Starting GNSS client");
	_client.run();
	return true;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Application::done() {
	Client::Application::done();
	SEISCOMP_INFO("Done");
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Application::exit(int returnCode) {
	Client::Application::exit(returnCode);
	_client.stop();
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


}
}
}
