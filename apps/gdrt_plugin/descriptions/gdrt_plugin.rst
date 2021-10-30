The GDRT plugin is a SeedLink plugin that converts GDRT (GFZ Displacement
Real-Time) UDP messages to Mini-SEED channels according to the following table:

+-------+---------------------+----------------+---------------------------------------+-------------------+
| Index | Field name          | Format         | Description                           | Mini-SEED channel |
+=======+=====================+================+=======================================+===================+
|   1   | Start of message    | character(1)   | A fixed character '>'                 |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|   2   | Station ID          | character(4)   | GDRT station ID                       |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|   3   | Epoch time          | integer(4)     | UTC time (year, month, day, hour,     |                   |
|       |                     | integer(2)     | minute, second)                       |                   |
|       |                     | integer(2)     |                                       |                   |
|       |                     | integer(2)     |                                       |                   |
|       |                     | integer(2)     |                                       |                   |
|       |                     | double(%5.2f)  |                                       |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|   4   | Solution type       | integer(2)     | 0: Single point positioning (SPP)     |     LBS           |
|       |                     |                +---------------------------------------+                   |
|       |                     |                | +1: Precise point positioning (PPP)   |                   |
|       |                     |                +---------------------------------------+                   |
|       |                     |                | +2: Precise point positioning         |                   |
|       |                     |                | ambiguity resolution (PPP-AR)         |                   |
|       |                     |                +---------------------------------------+                   |
|       |                     |                | +4: Precise point positioning         |                   |
|       |                     |                | regional augmentation (PPP-RA)        |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|   5   | Observation type    | integer(2)     | +1: GPS                               |     LBO           |
|       |                     |                +---------------------------------------+                   |
|       |                     |                | +2: GLONASS                           |                   |
|       |                     |                +---------------------------------------+                   |
|       |                     |                | +4: Galileo                           |                   |
|       |                     |                +---------------------------------------+                   |
|       |                     |                | +8: BDS                               |                   |
|       |                     |                +---------------------------------------+                   |
|       |                     |                | +16: Seismic data                     |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|   6   | Positioning type    | integer(2)     | 1: Coordinate fixed solution          |     LBP           |
|       |                     |                +---------------------------------------+                   |
|       |                     |                | 2: Static solution                    |                   |
|       |                     |                +---------------------------------------+                   |
|       |                     |                | 3: Kinematic solution                 |                   |
|       |                     |                +---------------------------------------+                   |
|       |                     |                | 4: Dynamic solution                   |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|   7   | Processing type     | integer(2)     | 1: Real-time solution                 |     LBT           |
|       |                     |                +---------------------------------------+                   |
|       |                     |                | 2: Post-processing solution           |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|   8   | Ratio of            | double(%6.2f)  | The ratio value of PPP ambiguty       |     LBR (×100)    |
|       | ambiguity fix       |                | fixing (larger value means more       |                   |
|       |                     |                | reliable ambiguity fixing)            |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|   9   | Number of           | integer(2)     | Number of satellites used for the     |     LBC (summed)  |
|       | satellites          | integer(2)     | solution (GPS, GLONASS, Galileo, BDS) |                   |
|       |                     | integer(2)     |                                       |                   |
|       |                     | integer(2)     |                                       |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|  10   | Coordinate X        | double(%14.4f) | Coordinates X, Y, and Z in the Earth  |     LBE           |
+-------+---------------------+----------------+ Centered Earth Fixed (ECEF)           +-------------------+
|  11   | Coordinate Y        | double(%14.4f) | coordinate system in meters           |     LBN           |
+-------+---------------------+----------------+                                       +-------------------+
|  12   | Coordinate Z        | double(%14.4f) |                                       |     LBZ           |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|  13   | Variance of         | double(%14.4f) | Variance of coordinates in meters     |     LB1           |
|       | coordinate X        |                |                                       |                   |
+-------+---------------------+----------------+                                       +-------------------+
|  14   | Variance of         | double(%14.4f) |                                       |     LB2           |
|       | coordinate y        |                |                                       |                   |
+-------+---------------------+----------------+                                       +-------------------+
|  15   | Variance of         | double(%14.4f) |                                       |     LB3           |
|       | coordinate Z        |                |                                       |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|  16   | Covariance of       | double(%14.4f) | Covariance of coordinates in meters   |     LB4           |
|       | coordinates X and Y |                |                                       |                   |
+-------+---------------------+----------------+                                       +-------------------+
|  17   | Covariance of       | double(%14.4f) |                                       |     LB5           |
|       | coordinates X and Z |                |                                       |                   |
+-------+---------------------+----------------+                                       +-------------------+
|  18   | Covariance of       | double(%14.4f) |                                       |     LB6           |
|       | coordinates Y and Z |                |                                       |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|  19   | Correction          | string(4)      | Name of orbit/clock/upd product and   |                   |
|       | information         |                | name of three used reference stations |                   |
|       |                     |                | in PPP-RA, separated with '+'         |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+
|  20   | End of message      | character(1)   | A fixed character '!'                 |                   |
+-------+---------------------+----------------+---------------------------------------+-------------------+

