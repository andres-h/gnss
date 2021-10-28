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

#ifndef SEISCOMP_APPS_GNSSPLUGIN_UDPCLIENT_H__
#define SEISCOMP_APPS_GNSSPLUGIN_UDPCLIENT_H__

#include <string>
#include <map>
#include <boost/asio.hpp>
#include <boost/array.hpp>

#include "station.h"


namespace Seiscomp {
namespace Applications {
namespace GNSSPlugin {


class UDPClient {
	public:
		void addStation(const std::string &key,
				const std::string &networkCode,
				const std::string &stationCode,
				const std::string &locationCode,
				double sampleRate);

		void run();
		void stop();

	private:
		boost::asio::io_service _ioService;
		boost::asio::ip::udp::socket _socket{_ioService};
		boost::asio::ip::udp::endpoint _remoteEndpoint;
		boost::array<char, 1024> _recvBuffer;
		std::map<std::string, StationPtr> _stations;

		void wait();
		void handleReceive(const boost::system::error_code& error, size_t bytesTransferred);
};


}
}
}


#endif
