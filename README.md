# UT-HEPfit
A HEPfit package to perform a Unitarity Triangle fit

#### To install HEPfit:
     
cd HEPfit/build/     
cmake .. -DLOCAL_INSTALL_ALL=ON -DNOMCMC=ON    
make    
make install

#### To make the event generator:

cd examples/EventGeneration   
make

#### To run the event generator:

The configuration files are in the folder called config. Then run:

./analysis config/StandardModel.conf 0

This will give you the central even corresponding to the central values in the config files

./analysis config/StandardModel.conf 10

will give you the central event and 10 random events

./analysis config/StandardModel.conf 10 SomeFolder

will do the above but instead of printing in the screen will save the parameter values and observables in a folder called GeneratedEvents/SomeFolder.


#### To make the MonteCarlo code:

cd examples/MonteCarloMode   
make

#### To run the Monte Carlo:

The configuration files are in the folder called config. Then run:

./analysis config/StandardModel.conf config/MonteCarlo.conf

Alternatively one can use openMPI (with N threads):

mpiexec -n N ./analysis config/StandardModel.conf config/MonteCarlo.conf

we recommend 1 chain per core. Please look into the MonteCarlo.conf for the settings


