
set MATLAB=C:\Program Files\MATLAB\R2022b

"C:\Program Files\MATLAB\R2022b\bin\win64\gmake" -f CPS_tare_Eva.mk  EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 TMW_EXTMODE_TESTING=0 COMBINE_OUTPUT_UPDATE_FCNS=0 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 OPTS="-DTGTCONN -DEXT_MODE -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=0"
