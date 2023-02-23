    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (CPS_Eva_P)
        ;%
            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% CPS_Eva_P.Gromit_Cal_tranp
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_Eva_P.M
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 36;

                    ;% CPS_Eva_P.c
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 37;

                    ;% CPS_Eva_P.k
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 38;

                    ;% CPS_Eva_P.mass_of_cylinder
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 39;

                    ;% CPS_Eva_P.start_position_cm
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 40;

                    ;% CPS_Eva_P.EncoderInput_InputFilter
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 41;

                    ;% CPS_Eva_P.AnalogOutput_MaxMissedTicks
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 42;

                    ;% CPS_Eva_P.AnalogOutput1_MaxMissedTicks
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 43;

                    ;% CPS_Eva_P.AnalogInput_MaxMissedTicks
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 44;

                    ;% CPS_Eva_P.AnalogInput2_MaxMissedTicks
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 45;

                    ;% CPS_Eva_P.AnalogInput1_MaxMissedTicks
                    section.data(12).logicalSrcIdx = 15;
                    section.data(12).dtTransOffset = 46;

                    ;% CPS_Eva_P.EncoderInput_MaxMissedTicks
                    section.data(13).logicalSrcIdx = 16;
                    section.data(13).dtTransOffset = 47;

                    ;% CPS_Eva_P.AnalogOutput_YieldWhenWaiting
                    section.data(14).logicalSrcIdx = 17;
                    section.data(14).dtTransOffset = 48;

                    ;% CPS_Eva_P.AnalogOutput1_YieldWhenWaiting
                    section.data(15).logicalSrcIdx = 18;
                    section.data(15).dtTransOffset = 49;

                    ;% CPS_Eva_P.AnalogInput_YieldWhenWaiting
                    section.data(16).logicalSrcIdx = 19;
                    section.data(16).dtTransOffset = 50;

                    ;% CPS_Eva_P.AnalogInput2_YieldWhenWaiting
                    section.data(17).logicalSrcIdx = 20;
                    section.data(17).dtTransOffset = 51;

                    ;% CPS_Eva_P.AnalogInput1_YieldWhenWaiting
                    section.data(18).logicalSrcIdx = 21;
                    section.data(18).dtTransOffset = 52;

                    ;% CPS_Eva_P.EncoderInput_YieldWhenWaiting
                    section.data(19).logicalSrcIdx = 22;
                    section.data(19).dtTransOffset = 53;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% CPS_Eva_P.AnalogOutput_Channels
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_Eva_P.AnalogOutput1_Channels
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_Eva_P.AnalogInput_Channels
                    section.data(3).logicalSrcIdx = 25;
                    section.data(3).dtTransOffset = 2;

                    ;% CPS_Eva_P.AnalogInput2_Channels
                    section.data(4).logicalSrcIdx = 26;
                    section.data(4).dtTransOffset = 8;

                    ;% CPS_Eva_P.AnalogInput1_Channels
                    section.data(5).logicalSrcIdx = 27;
                    section.data(5).dtTransOffset = 9;

                    ;% CPS_Eva_P.EncoderInput_Channels
                    section.data(6).logicalSrcIdx = 28;
                    section.data(6).dtTransOffset = 13;

                    ;% CPS_Eva_P.AnalogOutput_RangeMode
                    section.data(7).logicalSrcIdx = 29;
                    section.data(7).dtTransOffset = 14;

                    ;% CPS_Eva_P.AnalogOutput1_RangeMode
                    section.data(8).logicalSrcIdx = 30;
                    section.data(8).dtTransOffset = 15;

                    ;% CPS_Eva_P.AnalogInput_RangeMode
                    section.data(9).logicalSrcIdx = 31;
                    section.data(9).dtTransOffset = 16;

                    ;% CPS_Eva_P.AnalogInput2_RangeMode
                    section.data(10).logicalSrcIdx = 32;
                    section.data(10).dtTransOffset = 17;

                    ;% CPS_Eva_P.AnalogInput1_RangeMode
                    section.data(11).logicalSrcIdx = 33;
                    section.data(11).dtTransOffset = 18;

                    ;% CPS_Eva_P.AnalogOutput_VoltRange
                    section.data(12).logicalSrcIdx = 34;
                    section.data(12).dtTransOffset = 19;

                    ;% CPS_Eva_P.AnalogOutput1_VoltRange
                    section.data(13).logicalSrcIdx = 35;
                    section.data(13).dtTransOffset = 20;

                    ;% CPS_Eva_P.AnalogInput_VoltRange
                    section.data(14).logicalSrcIdx = 36;
                    section.data(14).dtTransOffset = 21;

                    ;% CPS_Eva_P.AnalogInput2_VoltRange
                    section.data(15).logicalSrcIdx = 37;
                    section.data(15).dtTransOffset = 22;

                    ;% CPS_Eva_P.AnalogInput1_VoltRange
                    section.data(16).logicalSrcIdx = 38;
                    section.data(16).dtTransOffset = 23;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 30;
            section.data(30)  = dumData; %prealloc

                    ;% CPS_Eva_P.Gain9_Gain
                    section.data(1).logicalSrcIdx = 39;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_Eva_P.AnalogFilterDesign_A_pr
                    section.data(2).logicalSrcIdx = 40;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_Eva_P.AnalogFilterDesign_B_pr
                    section.data(3).logicalSrcIdx = 41;
                    section.data(3).dtTransOffset = 8;

                    ;% CPS_Eva_P.AnalogFilterDesign_C_pr
                    section.data(4).logicalSrcIdx = 42;
                    section.data(4).dtTransOffset = 9;

                    ;% CPS_Eva_P.AnalogFilterDesign_InitialCondition
                    section.data(5).logicalSrcIdx = 43;
                    section.data(5).dtTransOffset = 10;

                    ;% CPS_Eva_P.Saturation_UpperSat
                    section.data(6).logicalSrcIdx = 44;
                    section.data(6).dtTransOffset = 11;

                    ;% CPS_Eva_P.Saturation_LowerSat
                    section.data(7).logicalSrcIdx = 45;
                    section.data(7).dtTransOffset = 12;

                    ;% CPS_Eva_P.DiscreteTimeIntegrator_gainval
                    section.data(8).logicalSrcIdx = 46;
                    section.data(8).dtTransOffset = 13;

                    ;% CPS_Eva_P.DiscreteTimeIntegrator_IC
                    section.data(9).logicalSrcIdx = 47;
                    section.data(9).dtTransOffset = 14;

                    ;% CPS_Eva_P.Saturation1_UpperSat
                    section.data(10).logicalSrcIdx = 48;
                    section.data(10).dtTransOffset = 15;

                    ;% CPS_Eva_P.Saturation1_LowerSat
                    section.data(11).logicalSrcIdx = 49;
                    section.data(11).dtTransOffset = 16;

                    ;% CPS_Eva_P.DiscreteTimeIntegrator1_gainval
                    section.data(12).logicalSrcIdx = 50;
                    section.data(12).dtTransOffset = 17;

                    ;% CPS_Eva_P.Saturation2_UpperSat
                    section.data(13).logicalSrcIdx = 51;
                    section.data(13).dtTransOffset = 18;

                    ;% CPS_Eva_P.Saturation2_LowerSat
                    section.data(14).logicalSrcIdx = 52;
                    section.data(14).dtTransOffset = 19;

                    ;% CPS_Eva_P.SineWave_Amp
                    section.data(15).logicalSrcIdx = 53;
                    section.data(15).dtTransOffset = 20;

                    ;% CPS_Eva_P.SineWave_Bias
                    section.data(16).logicalSrcIdx = 54;
                    section.data(16).dtTransOffset = 21;

                    ;% CPS_Eva_P.SineWave_Freq
                    section.data(17).logicalSrcIdx = 55;
                    section.data(17).dtTransOffset = 22;

                    ;% CPS_Eva_P.SineWave_Phase
                    section.data(18).logicalSrcIdx = 56;
                    section.data(18).dtTransOffset = 23;

                    ;% CPS_Eva_P.Constant3_Value
                    section.data(19).logicalSrcIdx = 57;
                    section.data(19).dtTransOffset = 24;

                    ;% CPS_Eva_P.Gain6_Gain
                    section.data(20).logicalSrcIdx = 58;
                    section.data(20).dtTransOffset = 25;

                    ;% CPS_Eva_P.Constant4_Value
                    section.data(21).logicalSrcIdx = 59;
                    section.data(21).dtTransOffset = 26;

                    ;% CPS_Eva_P.Gain10_Gain
                    section.data(22).logicalSrcIdx = 60;
                    section.data(22).dtTransOffset = 27;

                    ;% CPS_Eva_P.Bias_Bias
                    section.data(23).logicalSrcIdx = 61;
                    section.data(23).dtTransOffset = 28;

                    ;% CPS_Eva_P.Gain11_Gain
                    section.data(24).logicalSrcIdx = 62;
                    section.data(24).dtTransOffset = 34;

                    ;% CPS_Eva_P.Gain5_Gain
                    section.data(25).logicalSrcIdx = 63;
                    section.data(25).dtTransOffset = 35;

                    ;% CPS_Eva_P.Bias1_Bias
                    section.data(26).logicalSrcIdx = 64;
                    section.data(26).dtTransOffset = 36;

                    ;% CPS_Eva_P.Gain1_Gain
                    section.data(27).logicalSrcIdx = 65;
                    section.data(27).dtTransOffset = 37;

                    ;% CPS_Eva_P.Bias2_Bias
                    section.data(28).logicalSrcIdx = 66;
                    section.data(28).dtTransOffset = 38;

                    ;% CPS_Eva_P.Gain4_Gain
                    section.data(29).logicalSrcIdx = 67;
                    section.data(29).dtTransOffset = 39;

                    ;% CPS_Eva_P.Gain8_Gain
                    section.data(30).logicalSrcIdx = 68;
                    section.data(30).dtTransOffset = 40;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% CPS_Eva_P.AnalogFilterDesign_A_ir
                    section.data(1).logicalSrcIdx = 69;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_Eva_P.AnalogFilterDesign_A_jc
                    section.data(2).logicalSrcIdx = 70;
                    section.data(2).dtTransOffset = 7;

                    ;% CPS_Eva_P.AnalogFilterDesign_B_ir
                    section.data(3).logicalSrcIdx = 71;
                    section.data(3).dtTransOffset = 12;

                    ;% CPS_Eva_P.AnalogFilterDesign_B_jc
                    section.data(4).logicalSrcIdx = 72;
                    section.data(4).dtTransOffset = 13;

                    ;% CPS_Eva_P.AnalogFilterDesign_C_ir
                    section.data(5).logicalSrcIdx = 73;
                    section.data(5).dtTransOffset = 15;

                    ;% CPS_Eva_P.AnalogFilterDesign_C_jc
                    section.data(6).logicalSrcIdx = 74;
                    section.data(6).dtTransOffset = 16;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% CPS_Eva_P.Sineorcustomtrajectory_CurrentSetting
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_Eva_P.Signalorzero_CurrentSetting
                    section.data(2).logicalSrcIdx = 76;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_Eva_P.CPSorReference_CurrentSetting
                    section.data(3).logicalSrcIdx = 77;
                    section.data(3).dtTransOffset = 2;

                    ;% CPS_Eva_P.zeropitchorconstant_CurrentSetting
                    section.data(4).logicalSrcIdx = 78;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (CPS_Eva_B)
        ;%
            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% CPS_Eva_B.UnitDelay
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_Eva_B.AnalogFilterDesign
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_Eva_B.Saturation
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% CPS_Eva_B.DiscreteTimeIntegrator
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% CPS_Eva_B.Saturation1
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% CPS_Eva_B.DiscreteTimeIntegrator1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% CPS_Eva_B.Saturation2
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% CPS_Eva_B.Gain6
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% CPS_Eva_B.Gain
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% CPS_Eva_B.Gain11
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 14;

                    ;% CPS_Eva_B.Gain5
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 15;

                    ;% CPS_Eva_B.Gain2
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 16;

                    ;% CPS_Eva_B.TmpSignalConversionAtToWorkspace1Inport1
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 17;

                    ;% CPS_Eva_B.Sum1
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 22;

                    ;% CPS_Eva_B.Gain4
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 23;

                    ;% CPS_Eva_B.MeasuredPosition
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 27;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (CPS_Eva_DW)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% CPS_Eva_DW.UnitDelay_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_Eva_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_Eva_DW.DiscreteTimeIntegrator1_DSTATE
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% CPS_Eva_DW.FromWs_PWORK.TimePtr
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_Eva_DW.AnalogOutput_PWORK
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_Eva_DW.AnalogOutput1_PWORK
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% CPS_Eva_DW.AnalogInput_PWORK
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% CPS_Eva_DW.AnalogInput2_PWORK
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% CPS_Eva_DW.AnalogInput1_PWORK
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% CPS_Eva_DW.EncoderInput_PWORK
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% CPS_Eva_DW.Scope3_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% CPS_Eva_DW.ToWorkspace_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

                    ;% CPS_Eva_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 9;

                    ;% CPS_Eva_DW.ToWorkspace3_PWORK.LoggedData
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 10;

                    ;% CPS_Eva_DW.ToWorkspace2_PWORK.LoggedData
                    section.data(12).logicalSrcIdx = 14;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CPS_Eva_DW.FromWs_IWORK.PrevIndex
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CPS_Eva_DW.DiscreteTimeIntegrator1_SYSTEM_ENABLE
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1543919336;
    targMap.checksum1 = 3857435886;
    targMap.checksum2 = 3412776513;
    targMap.checksum3 = 1096289326;

