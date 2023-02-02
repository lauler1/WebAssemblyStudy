#This is the right way, all sources that are not intended to become an
# executable (e.g. no main()) shall become a library
# https://matgomes.com/add-library-cmake-create-libraries/
# https://crascit.com/2016/01/31/enhanced-source-file-handling-with-target_sources/
target_sources(myLib
    PRIVATE
        hellofunc.c
)
