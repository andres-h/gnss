import os

'''
Plugin handler for the GNSS plugin.
'''
class SeedlinkPluginHandler:
    def __init__(self):
        self.instances = {}
        self.stations = {}

    def push(self, seedlink):
        try: gnssStation = seedlink.param('sources.gnss.station')
        except: gnssStation = seedlink.param('seedlink.station.code')

        seedlink.setParam('sources.gnss.station', gnssStation);

        try: locationCode = seedlink.param('sources.gnss.locationCode')
        except: locationCode = ""

        seedlink.setParam('sources.gnss.locationCode', locationCode);

        try: sampleRate = float(seedlink.param('sources.gnss.sampleRate'))
        except: sampleRate = 1.0

        seedlink.setParam('sources.gnss.sampleRate', sampleRate)

        try: udpport = int(seedlink.param('sources.gnss.udpport'))
        except: udpport = 9999

        seedlink.setParam('sources.gnss.udpport', udpport);

        try:
            n = self.instances[udpport]

        except KeyError:
            n = len(self.instances)
            self.instances[udpport] = n

        stationsFrom = os.path.join(seedlink.config_dir, "gnss%d.stations" % n)
        seedlink.setParam('sources.gnss.stationsFrom', stationsFrom)

        try:
            stationList = self.stations[stationsFrom]

        except KeyError:
            stationList = []
            self.stations[stationsFrom] = stationList

        stationList.append((gnssStation,
                            seedlink.param('seedlink.station.network'),
                            seedlink.param('seedlink.station.code'),
                            locationCode if locationCode else "--",
                            sampleRate))

        return udpport


    def flush(self, seedlink):
        for stationsFrom, stations in self.stations.items():
            with open(stationsFrom, "w") as fd:
                for s in stations:
                    fd.write("%s %s %s %s %f\n" % s)
 
