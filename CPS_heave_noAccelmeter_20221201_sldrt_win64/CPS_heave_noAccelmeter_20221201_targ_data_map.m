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
        ;% Auto data (CPS_heave_noAccelmeter_20221201_P)
        ;%
            section.nData     = 17;
            section.data(17)  = dumData; %prealloc

                    ;% CPS_heave_noAccelmeter_20221201_P.M
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_heave_noAccelmeter_20221201_P.Wallace_Cal_tranp
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_heave_noAccelmeter_20221201_P.c
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 37;

                    ;% CPS_heave_noAccelmeter_20221201_P.input_heave_meters
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 38;

                    ;% CPS_heave_noAccelmeter_20221201_P.k
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 39;

                    ;% CPS_heave_noAccelmeter_20221201_P.start_position_meters
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 40;

                    ;% CPS_heave_noAccelmeter_20221201_P.EncoderInput_InputFilter
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 41;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogOutput1_MaxMissedTicks
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 42;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogOutput2_MaxMissedTicks
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 43;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogInput1_MaxMissedTicks
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 44;

                    ;% CPS_heave_noAccelmeter_20221201_P.EncoderInput_MaxMissedTicks
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 45;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogInput2_MaxMissedTicks
                    section.data(12).logicalSrcIdx = 15;
                    section.data(12).dtTransOffset = 46;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogOutput1_YieldWhenWaiting
                    section.data(13).logicalSrcIdx = 16;
                    section.data(13).dtTransOffset = 47;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogOutput2_YieldWhenWaiting
                    section.data(14).logicalSrcIdx = 17;
                    section.data(14).dtTransOffset = 48;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogInput1_YieldWhenWaiting
                    section.data(15).logicalSrcIdx = 18;
                    section.data(15).dtTransOffset = 49;

                    ;% CPS_heave_noAccelmeter_20221201_P.EncoderInput_YieldWhenWaiting
                    section.data(16).logicalSrcIdx = 19;
                    section.data(16).dtTransOffset = 50;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogInput2_YieldWhenWaiting
                    section.data(17).logicalSrcIdx = 20;
                    section.data(17).dtTransOffset = 51;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogOutput1_Channels
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogOutput2_Channels
                    section.data(2).logicalSrcIdx = 22;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogInput1_Channels
                    section.data(3).logicalSrcIdx = 23;
                    section.data(3).dtTransOffset = 2;

                    ;% CPS_heave_noAccelmeter_20221201_P.EncoderInput_Channels
                    section.data(4).logicalSrcIdx = 24;
                    section.data(4).dtTransOffset = 11;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogInput2_Channels
                    section.data(5).logicalSrcIdx = 25;
                    section.data(5).dtTransOffset = 12;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogOutput1_RangeMode
                    section.data(6).logicalSrcIdx = 26;
                    section.data(6).dtTransOffset = 16;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogOutput2_RangeMode
                    section.data(7).logicalSrcIdx = 27;
                    section.data(7).dtTransOffset = 17;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogInput1_RangeMode
                    section.data(8).logicalSrcIdx = 28;
                    section.data(8).dtTransOffset = 18;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogInput2_RangeMode
                    section.data(9).logicalSrcIdx = 29;
                    section.data(9).dtTransOffset = 19;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogOutput1_VoltRange
                    section.data(10).logicalSrcIdx = 30;
                    section.data(10).dtTransOffset = 20;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogOutput2_VoltRange
                    section.data(11).logicalSrcIdx = 31;
                    section.data(11).dtTransOffset = 21;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogInput1_VoltRange
                    section.data(12).logicalSrcIdx = 32;
                    section.data(12).dtTransOffset = 22;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogInput2_VoltRange
                    section.data(13).logicalSrcIdx = 33;
                    section.data(13).dtTransOffset = 23;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 28;
            section.data(28)  = dumData; %prealloc

                    ;% CPS_heave_noAccelmeter_20221201_P.torad_Gain
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogFilterDesign_A_pr
                    section.data(2).logicalSrcIdx = 35;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogFilterDesign_B_pr
                    section.data(3).logicalSrcIdx = 36;
                    section.data(3).dtTransOffset = 8;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogFilterDesign_C_pr
                    section.data(4).logicalSrcIdx = 37;
                    section.data(4).dtTransOffset = 9;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogFilterDesign_InitialCondition
                    section.data(5).logicalSrcIdx = 38;
                    section.data(5).dtTransOffset = 10;

                    ;% CPS_heave_noAccelmeter_20221201_P.Integrator_gainval
                    section.data(6).logicalSrcIdx = 39;
                    section.data(6).dtTransOffset = 11;

                    ;% CPS_heave_noAccelmeter_20221201_P.Integrator_IC
                    section.data(7).logicalSrcIdx = 40;
                    section.data(7).dtTransOffset = 12;

                    ;% CPS_heave_noAccelmeter_20221201_P.Integrator2_gainval
                    section.data(8).logicalSrcIdx = 41;
                    section.data(8).dtTransOffset = 13;

                    ;% CPS_heave_noAccelmeter_20221201_P.SineWave_Amp
                    section.data(9).logicalSrcIdx = 42;
                    section.data(9).dtTransOffset = 14;

                    ;% CPS_heave_noAccelmeter_20221201_P.SineWave_Bias
                    section.data(10).logicalSrcIdx = 43;
                    section.data(10).dtTransOffset = 15;

                    ;% CPS_heave_noAccelmeter_20221201_P.SineWave_Freq
                    section.data(11).logicalSrcIdx = 44;
                    section.data(11).dtTransOffset = 16;

                    ;% CPS_heave_noAccelmeter_20221201_P.SineWave_Phase
                    section.data(12).logicalSrcIdx = 45;
                    section.data(12).dtTransOffset = 17;

                    ;% CPS_heave_noAccelmeter_20221201_P.Zero_Value
                    section.data(13).logicalSrcIdx = 46;
                    section.data(13).dtTransOffset = 18;

                    ;% CPS_heave_noAccelmeter_20221201_P.positionoutmtoV_Gain
                    section.data(14).logicalSrcIdx = 47;
                    section.data(14).dtTransOffset = 19;

                    ;% CPS_heave_noAccelmeter_20221201_P.offsetdeg_Value
                    section.data(15).logicalSrcIdx = 48;
                    section.data(15).dtTransOffset = 20;

                    ;% CPS_heave_noAccelmeter_20221201_P.angleoutdeg1_Gain
                    section.data(16).logicalSrcIdx = 49;
                    section.data(16).dtTransOffset = 21;

                    ;% CPS_heave_noAccelmeter_20221201_P.forcebias_Bias
                    section.data(17).logicalSrcIdx = 50;
                    section.data(17).dtTransOffset = 22;

                    ;% CPS_heave_noAccelmeter_20221201_P.accelbiasV_Bias
                    section.data(18).logicalSrcIdx = 51;
                    section.data(18).dtTransOffset = 28;

                    ;% CPS_heave_noAccelmeter_20221201_P.accelVtoms2_Gain
                    section.data(19).logicalSrcIdx = 52;
                    section.data(19).dtTransOffset = 29;

                    ;% CPS_heave_noAccelmeter_20221201_P.loadmass_Gain
                    section.data(20).logicalSrcIdx = 53;
                    section.data(20).dtTransOffset = 30;

                    ;% CPS_heave_noAccelmeter_20221201_P.Zeroforce_Value
                    section.data(21).logicalSrcIdx = 54;
                    section.data(21).dtTransOffset = 31;

                    ;% CPS_heave_noAccelmeter_20221201_P.cmm_Gain
                    section.data(22).logicalSrcIdx = 55;
                    section.data(22).dtTransOffset = 32;

                    ;% CPS_heave_noAccelmeter_20221201_P.countstocm_Gain
                    section.data(23).logicalSrcIdx = 56;
                    section.data(23).dtTransOffset = 33;

                    ;% CPS_heave_noAccelmeter_20221201_P.PitchVtorad_Gain
                    section.data(24).logicalSrcIdx = 57;
                    section.data(24).dtTransOffset = 34;

                    ;% CPS_heave_noAccelmeter_20221201_P.Heaveoffset_Value
                    section.data(25).logicalSrcIdx = 58;
                    section.data(25).dtTransOffset = 35;

                    ;% CPS_heave_noAccelmeter_20221201_P.virtualmasskg_Gain
                    section.data(26).logicalSrcIdx = 59;
                    section.data(26).dtTransOffset = 36;

                    ;% CPS_heave_noAccelmeter_20221201_P.Bias_Bias
                    section.data(27).logicalSrcIdx = 60;
                    section.data(27).dtTransOffset = 37;

                    ;% CPS_heave_noAccelmeter_20221201_P.conversion1_Gain
                    section.data(28).logicalSrcIdx = 61;
                    section.data(28).dtTransOffset = 38;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogFilterDesign_A_ir
                    section.data(1).logicalSrcIdx = 62;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogFilterDesign_A_jc
                    section.data(2).logicalSrcIdx = 63;
                    section.data(2).dtTransOffset = 7;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogFilterDesign_B_ir
                    section.data(3).logicalSrcIdx = 64;
                    section.data(3).dtTransOffset = 12;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogFilterDesign_B_jc
                    section.data(4).logicalSrcIdx = 65;
                    section.data(4).dtTransOffset = 13;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogFilterDesign_C_ir
                    section.data(5).logicalSrcIdx = 66;
                    section.data(5).dtTransOffset = 15;

                    ;% CPS_heave_noAccelmeter_20221201_P.AnalogFilterDesign_C_jc
                    section.data(6).logicalSrcIdx = 67;
                    section.data(6).dtTransOffset = 16;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% CPS_heave_noAccelmeter_20221201_P.sineorcustomtraj_CurrentSetting
                    section.data(1).logicalSrcIdx = 68;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_heave_noAccelmeter_20221201_P.signalorzero_CurrentSetting
                    section.data(2).logicalSrcIdx = 69;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_heave_noAccelmeter_20221201_P.CPSorreference_CurrentSetting
                    section.data(3).logicalSrcIdx = 70;
                    section.data(3).dtTransOffset = 2;

                    ;% CPS_heave_noAccelmeter_20221201_P.Pitchzeroorconstant_CurrentSetting
                    section.data(4).logicalSrcIdx = 71;
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
        ;% Auto data (CPS_heave_noAccelmeter_20221201_B)
        ;%
            section.nData     = 21;
            section.data(21)  = dumData; %prealloc

                    ;% CPS_heave_noAccelmeter_20221201_B.Virtualdampingkgs
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_heave_noAccelmeter_20221201_B.VirtualspringNm
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_heave_noAccelmeter_20221201_B.LateralforcefilteredN
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% CPS_heave_noAccelmeter_20221201_B.UnitDelay
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% CPS_heave_noAccelmeter_20221201_B.inversemass1kg
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% CPS_heave_noAccelmeter_20221201_B.Integrator
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% CPS_heave_noAccelmeter_20221201_B.Integrator2
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% CPS_heave_noAccelmeter_20221201_B.positionoutmtoV
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% CPS_heave_noAccelmeter_20221201_B.Pitchzeroorconstant
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% CPS_heave_noAccelmeter_20221201_B.conversionmatrix
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% CPS_heave_noAccelmeter_20221201_B.InertialloadN
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 15;

                    ;% CPS_heave_noAccelmeter_20221201_B.TmpSignalConversionAtForcesInport1
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 16;

                    ;% CPS_heave_noAccelmeter_20221201_B.Zeroforce
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 21;

                    ;% CPS_heave_noAccelmeter_20221201_B.Prescribedheavecm
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 22;

                    ;% CPS_heave_noAccelmeter_20221201_B.Encodermeasuredheavecm
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 23;

                    ;% CPS_heave_noAccelmeter_20221201_B.Pitchmeasuredrad
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 24;

                    ;% CPS_heave_noAccelmeter_20221201_B.dampingspeed
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 25;

                    ;% CPS_heave_noAccelmeter_20221201_B.stiffnessdisplacement
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 26;

                    ;% CPS_heave_noAccelmeter_20221201_B.Sum1
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 27;

                    ;% CPS_heave_noAccelmeter_20221201_B.Sum2
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 28;

                    ;% CPS_heave_noAccelmeter_20221201_B.conversion1
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 29;

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
        ;% Auto data (CPS_heave_noAccelmeter_20221201_DW)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% CPS_heave_noAccelmeter_20221201_DW.UnitDelay_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_heave_noAccelmeter_20221201_DW.Integrator_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_heave_noAccelmeter_20221201_DW.Integrator2_DSTATE
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% CPS_heave_noAccelmeter_20221201_DW._PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_heave_noAccelmeter_20221201_DW._PWORK_g.LoggedData
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% CPS_heave_noAccelmeter_20221201_DW.FromWs_PWORK.TimePtr
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% CPS_heave_noAccelmeter_20221201_DW.AnalogOutput1_PWORK
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% CPS_heave_noAccelmeter_20221201_DW.AnalogOutput2_PWORK
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% CPS_heave_noAccelmeter_20221201_DW.AnalogInput1_PWORK
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% CPS_heave_noAccelmeter_20221201_DW.EncoderInput_PWORK
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% CPS_heave_noAccelmeter_20221201_DW.AnalogInput2_PWORK
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% CPS_heave_noAccelmeter_20221201_DW.Forces_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

                    ;% CPS_heave_noAccelmeter_20221201_DW.Lateralforce_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 9;

                    ;% CPS_heave_noAccelmeter_20221201_DW.end_voltage_PWORK.LoggedData
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 10;

                    ;% CPS_heave_noAccelmeter_20221201_DW.heave_PWORK.LoggedData
                    section.data(12).logicalSrcIdx = 14;
                    section.data(12).dtTransOffset = 11;

                    ;% CPS_heave_noAccelmeter_20221201_DW.pitch_PWORK.LoggedData
                    section.data(13).logicalSrcIdx = 15;
                    section.data(13).dtTransOffset = 12;

                    ;% CPS_heave_noAccelmeter_20221201_DW.torquez_PWORK.LoggedData
                    section.data(14).logicalSrcIdx = 16;
                    section.data(14).dtTransOffset = 13;

                    ;% CPS_heave_noAccelmeter_20221201_DW.velocity_PWORK.LoggedData
                    section.data(15).logicalSrcIdx = 17;
                    section.data(15).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CPS_heave_noAccelmeter_20221201_DW.FromWs_IWORK.PrevIndex
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% CPS_heave_noAccelmeter_20221201_DW.Integrator_SYSTEM_ENABLE
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% CPS_heave_noAccelmeter_20221201_DW.Integrator2_SYSTEM_ENABLE
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

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


    targMap.checksum0 = 2955273506;
    targMap.checksum1 = 545990859;
    targMap.checksum2 = 2995946953;
    targMap.checksum3 = 323796900;

