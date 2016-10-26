//----------------------------------------------------------
//
// Code generated with Faust 0.9.81 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>
#ifndef FAUSTPOWER
#define FAUSTPOWER
#include <cmath>
template <int N> inline int faustpower(int x)              { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline int faustpower<0>(int x)            { return 1; }
template <> 	 inline int faustpower<1>(int x)            { return x; }
template <> 	 inline int faustpower<2>(int x)            { return x*x; }
template <int N> inline float faustpower(float x)            { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline float faustpower<0>(float x)          { return 1; }
template <> 	 inline float faustpower<1>(float x)          { return x; }
template <> 	 inline float faustpower<2>(float x)          { return x*x; }
#endif
// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Romain Michon (rmichonATccrmaDOTstanfordDOTedu)
// Description: Simple Faust architecture file to easily integrate a Faust DSP module
// in a JUCE project

// needed by any Faust arch file
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>

/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


// allows to control a Faust DSP module in a simple manner by using parameter's path
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <vector>
#include <map>
#include <string>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust User Interface
 * This abstract class contains only the method that the faust compiler can
 * generate to describe a DSP interface.
 ******************************************************************************/

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    protected:
    
        UI* fUI;

    public:
    
        DecoratorUI(UI* ui = 0):fUI(ui)
        {}

        virtual ~DecoratorUI() { delete fUI; }

        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }

        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
            { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 	
            { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 			
            { fUI->addNumEntry(label, zone, init, min, max, step); }

        // -- passive widgets	
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
            { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
            { fUI->addVerticalBargraph(label, zone, min, max); }

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }

};

#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H

/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, float value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        float getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return 0.;
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return fPathZoneMap.size(); }
        
        std::string getParamAdress(int index) 
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
};

#endif // FAUST_MAPUI_H

// needed by any Faust arch file
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

//----------------------------------------------------------------
//  Signal processor definition
//----------------------------------------------------------------

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        virtual int getNumInputs() = 0;
        virtual int getNumOutputs() = 0;
        virtual void buildUserInterface(UI* ui_interface) = 0;
        virtual int getSampleRate() = 0;
        virtual void init(int samplingRate) = 0;
        virtual void instanceInit(int samplingRate) = 0;
        virtual dsp* clone() = 0;
        virtual void metadata(Meta* m) = 0;
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { return fDSP->metadata(m); }
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
       
};

//----------------------------------------------------------------
// On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
// flags to avoid costly denormals
//----------------------------------------------------------------

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif

// tags used by the Faust compiler to paste the generated c++ code
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifndef FAUSTCLASS 
#define FAUSTCLASS OneVoice
#endif

class OneVoice : public dsp {
  private:
	class SIG0 {
	  private:
		int 	fSamplingFreq;
		int 	iRec5[2];
	  public:
		int getNumInputs() 	{ return 0; }
		int getNumOutputs() 	{ return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			for (int i=0; i<2; i++) iRec5[i] = 0;
		}
		void fill (int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec5[0] = (1 + iRec5[1]);
				output[i] = sinf((9.58738e-05f * float((iRec5[0] - 1))));
				// post processing
				iRec5[1] = iRec5[0];
			}
		}
	};


	class SIG1 {
	  private:
		int 	fSamplingFreq;
		int 	iRec9[2];
	  public:
		int getNumInputs() 	{ return 0; }
		int getNumOutputs() 	{ return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			for (int i=0; i<2; i++) iRec9[i] = 0;
		}
		void fill (int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec9[0] = (1 + iRec9[1]);
				output[i] = cosf((9.58738e-05f * float((iRec9[0] - 1))));
				// post processing
				iRec9[1] = iRec9[0];
			}
		}
	};


	FAUSTFLOAT 	fslider0;
	float 	fRec0[2];
	float 	fConst0;
	float 	fConst1;
	float 	fConst2;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	float 	fRec4[2];
	static float 	ftbl0[65536];
	FAUSTFLOAT 	fslider3;
	float 	fRec7[2];
	float 	fRec6[2];
	FAUSTFLOAT 	fslider4;
	float 	fRec8[2];
	static float 	ftbl1[65536];
	FAUSTFLOAT 	fslider5;
	float 	fRec10[2];
	FAUSTFLOAT 	fcheckbox0;
	float 	fRec11[2];
	FAUSTFLOAT 	fcheckbox1;
	float 	fRec12[2];
	FAUSTFLOAT 	fslider6;
	float 	fRec13[2];
	float 	fRec2[2];
	FAUSTFLOAT 	fslider7;
	float 	fRec14[2];
	FAUSTFLOAT 	fcheckbox2;
	float 	fRec15[2];
	FAUSTFLOAT 	fcheckbox3;
	float 	fRec16[2];
	FAUSTFLOAT 	fslider8;
	float 	fRec18[2];
	float 	fRec17[2];
	FAUSTFLOAT 	fslider9;
	float 	fRec19[2];
	FAUSTFLOAT 	fcheckbox4;
	FAUSTFLOAT 	fslider10;
	float 	fRec21[2];
	float 	fRec20[2];
	FAUSTFLOAT 	fslider11;
	float 	fRec24[2];
	FAUSTFLOAT 	fslider12;
	float 	fRec25[2];
	float 	fRec23[2];
	float 	fConst3;
	FAUSTFLOAT 	fslider13;
	float 	fRec26[2];
	float 	fRec22[2];
	float 	fConst4;
	FAUSTFLOAT 	fslider14;
	float 	fRec27[2];
	FAUSTFLOAT 	fslider15;
	float 	fRec28[2];
	float 	fRec1[3];
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) 	{ 
		m->declare("envelope.lib/name", "Faust Envelope Library");
		m->declare("envelope.lib/version", "0.0");
		m->declare("envelope.lib/author", "GRAME");
		m->declare("envelope.lib/copyright", "GRAME");
		m->declare("envelope.lib/license", "LGPL with exception");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/version", "2.0");
		m->declare("oscillator.lib/name", "Faust Oscillator Library");
		m->declare("oscillator.lib/version", "0.0");
		m->declare("basic.lib/name", "Faust Basic Element Library");
		m->declare("signal.lib/name", "Faust Signal Routing Library");
		m->declare("signal.lib/version", "0.0");
		m->declare("math.lib/name", "Faust Math Library");
		m->declare("math.lib/version", "2.0");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("basic.lib/version", "0.0");
	}

	virtual int getNumInputs() 	{ return 0; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
		SIG0 sig0;
		sig0.init(samplingFreq);
		sig0.fill(65536,ftbl0);
		SIG1 sig1;
		sig1.init(samplingFreq);
		sig1.fill(65536,ftbl1);
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 0.5f;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		fConst0 = min(1.92e+05f, max(1.0f, (float)fSamplingFreq));
		fConst1 = float(fConst0);
		fConst2 = (1.0f / fConst1);
		fslider1 = 4.4e+02f;
		fslider2 = 0.0f;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		fslider3 = 6.0f;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		fslider4 = 0.0f;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		fslider5 = 0.5f;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		fcheckbox0 = 0.0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		fcheckbox1 = 0.0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		fslider6 = 0.0f;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		fslider7 = 0.5f;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		fcheckbox2 = 0.0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		fcheckbox3 = 0.0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		fslider8 = 6.0f;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		fslider9 = 0.0f;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		fcheckbox4 = 0.0;
		fslider10 = 0.5f;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		fslider11 = 0.1f;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		fslider12 = 0.1f;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		fConst3 = (1.0f / fConst0);
		fslider13 = 75.0f;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		fConst4 = (62.831852f / fConst0);
		fslider14 = 9.0f;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		fslider15 = 7.0f;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual dsp* clone() {
		return new OneVoice();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openHorizontalBox("voice");
		interface->addVerticalSlider("Q", &fslider15, 7.0f, 1.0f, 2e+01f, 0.001f);
		interface->addVerticalSlider("att", &fslider11, 0.1f, 0.0f, 2.0f, 0.0001f);
		interface->addVerticalSlider("cutoff", &fslider14, 9.0f, 0.0f, 9.0f, 0.001f);
		interface->addVerticalSlider("del", &fslider12, 0.1f, 0.0f, 2.0f, 0.0001f);
		interface->addVerticalSlider("freq", &fslider1, 4.4e+02f, 2e+01f, 2e+04f, 0.01f);
		interface->addVerticalSlider("gain", &fslider0, 0.5f, 0.0f, 1.0f, 0.01f);
		interface->addVerticalSlider("modWheel", &fslider6, 0.0f, 0.0f, 127.0f, 1.0f);
		interface->addVerticalSlider("pitchBend", &fslider2, 0.0f, -2.0f, 2.0f, 5e-05f);
		interface->addVerticalSlider("rel", &fslider10, 0.5f, 0.0f, 4.0f, 0.0001f);
		interface->addVerticalSlider("sus", &fslider13, 75.0f, 0.0f, 1e+02f, 0.1f);
		interface->addCheckButton("tremMWOn", &fcheckbox3);
		interface->addCheckButton("tremOn", &fcheckbox2);
		interface->addVerticalSlider("tremPhase", &fslider9, 0.0f, 0.0f, 1.0f, 0.001f);
		interface->addVerticalSlider("tremrate", &fslider8, 6.0f, 2.0f, 1e+01f, 0.001f);
		interface->addVerticalSlider("tremstr", &fslider7, 0.5f, 0.0f, 1.0f, 0.001f);
		interface->addCheckButton("trig", &fcheckbox4);
		interface->addCheckButton("vibMWOn", &fcheckbox1);
		interface->addCheckButton("vibOn", &fcheckbox0);
		interface->addVerticalSlider("vibPhase", &fslider4, 0.0f, 0.0f, 1.0f, 0.0001f);
		interface->addVerticalSlider("vibrate", &fslider3, 6.0f, 2.0f, 1e+01f, 0.001f);
		interface->addVerticalSlider("vibstr", &fslider5, 0.5f, 0.0f, 1.0f, 0.001f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.001f * float(fslider0));
		float 	fSlow1 = float(fslider1);
		float 	fSlow2 = (0.001f * float(fslider2));
		float 	fSlow3 = (0.001f * float(fslider3));
		float 	fSlow4 = (0.001f * float(fslider4));
		float 	fSlow5 = (0.001f * float(fslider5));
		float 	fSlow6 = (0.001f * float(fcheckbox0));
		float 	fSlow7 = (0.001f * float(fcheckbox1));
		float 	fSlow8 = (0.001f * float(fslider6));
		float 	fSlow9 = (0.001f * float(fslider7));
		float 	fSlow10 = (0.001f * float(fcheckbox2));
		float 	fSlow11 = (0.001f * float(fcheckbox3));
		float 	fSlow12 = (0.001f * float(fslider8));
		float 	fSlow13 = (0.001f * float(fslider9));
		float 	fSlow14 = float(fcheckbox4);
		int 	iSlow15 = (fSlow14 > 0);
		int 	iSlow16 = int((iSlow15 > 0));
		float 	fSlow17 = (0.001f * float(fslider10));
		int 	iSlow18 = (1 - iSlow15);
		int 	iSlow19 = faustpower<2>(iSlow15);
		int 	iSlow20 = int(((fSlow14 == 0) > 0));
		float 	fSlow21 = (0.001f * float(fslider11));
		float 	fSlow22 = (0.001f * float(fslider12));
		float 	fSlow23 = (0.01f * fSlow14);
		float 	fSlow24 = (0.001f * float(fslider13));
		float 	fSlow25 = (0.001f * float(fslider14));
		float 	fSlow26 = (0.001f * float(fslider15));
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fRec0[0] = (fSlow0 + (0.999f * fRec0[1]));
			fRec4[0] = (fSlow2 + (0.999f * fRec4[1]));
			fRec7[0] = (fSlow3 + (0.999f * fRec7[1]));
			float fTemp0 = (fRec6[1] + (fConst2 * fRec7[0]));
			fRec6[0] = (fTemp0 - floorf(fTemp0));
			int iTemp1 = int((65536.0f * fRec6[0]));
			fRec8[0] = (fSlow4 + (0.999f * fRec8[1]));
			float fTemp2 = (6.2831855f * fRec8[0]);
			fRec10[0] = (fSlow5 + (0.999f * fRec10[1]));
			fRec11[0] = (fSlow6 + (0.999f * fRec11[1]));
			fRec12[0] = (fSlow7 + (0.999f * fRec12[1]));
			fRec13[0] = (fSlow8 + (0.999f * fRec13[1]));
			float fTemp3 = float(max(1e-07f, fabsf(((fSlow1 * powf(2,(0.083333336f * fRec4[0]))) + (10 * ((((ftbl0[iTemp1] * cosf(fTemp2)) + (ftbl1[iTemp1] * sinf(fTemp2))) * fRec10[0]) * (fRec11[0] + (fRec12[0] * fRec13[0]))))))));
			float fTemp4 = (fRec2[1] + (fConst2 * fTemp3));
			float fTemp5 = (fTemp4 - 1);
			int iTemp6 = int((fTemp5 < 0));
			fRec2[0] = ((iTemp6)?fTemp4:fTemp5);
			float 	fRec3 = ((iTemp6)?fTemp4:(fTemp4 + (fTemp5 * (1 - (fConst1 / fTemp3)))));
			fRec14[0] = (fSlow9 + (0.999f * fRec14[1]));
			fRec15[0] = (fSlow10 + (0.999f * fRec15[1]));
			fRec16[0] = (fSlow11 + (0.999f * fRec16[1]));
			fRec18[0] = (fSlow12 + (0.999f * fRec18[1]));
			float fTemp7 = (fRec17[1] + (fConst2 * fRec18[0]));
			fRec17[0] = (fTemp7 - floorf(fTemp7));
			int iTemp8 = int((65536.0f * fRec17[0]));
			fRec19[0] = (fSlow13 + (0.999f * fRec19[1]));
			float fTemp9 = (6.2831855f * fRec19[0]);
			fRec21[0] = (fSlow17 + (0.999f * fRec21[1]));
			float fTemp10 = (fConst0 * fRec21[0]);
			fRec20[0] = ((iSlow16)?0:min(fTemp10, (1 + fRec20[1])));
			fRec24[0] = (fSlow21 + (0.999f * fRec24[1]));
			fRec25[0] = (fSlow22 + (0.999f * fRec25[1]));
			float fTemp11 = (fConst0 * (fRec24[0] + fRec25[0]));
			fRec23[0] = ((iSlow20)?0:min(fTemp11, (1 + fRec23[1])));
			float fTemp12 = (fConst0 * fRec24[0]);
			int iTemp13 = int((fRec23[0] < fTemp12));
			fRec26[0] = (fSlow24 + (0.999f * fRec26[1]));
			float fTemp14 = (fSlow23 * fRec26[0]);
			fRec22[0] = ((iSlow18 * fRec22[1]) + (iSlow19 * ((iTemp13)?((int((fRec23[0] < 0)))?0:((iTemp13)?(fConst3 * (fRec23[0] / fRec24[0])):1)):((int((fRec23[0] < fTemp11)))?(1 + (fConst3 * (((fRec23[0] - fTemp12) * (fTemp14 - 1)) / fRec25[0]))):fTemp14))));
			float fTemp15 = ((int((fRec20[0] < 0)))?fRec22[0]:((int((fRec20[0] < fTemp10)))?(fRec22[0] + (fConst3 * ((fRec20[0] * (0 - fRec22[0])) / fRec21[0]))):0));
			fRec27[0] = (fSlow25 + (0.999f * fRec27[1]));
			float fTemp16 = tanf((fConst4 * powf(2,fRec27[0])));
			float fTemp17 = (1.0f / fTemp16);
			fRec28[0] = (fSlow26 + (0.999f * fRec28[1]));
			float fTemp18 = (1.0f / fRec28[0]);
			float fTemp19 = (1 + ((fTemp17 + fTemp18) / fTemp16));
			fRec1[0] = ((((fRec0[0] * ((2 * fRec3) - 1)) * (1 + ((fRec14[0] * (fRec15[0] + (fRec13[0] * fRec16[0]))) * ((0.5f * (1.0f + ((ftbl0[iTemp8] * cosf(fTemp9)) + (ftbl1[iTemp8] * sinf(fTemp9))))) - 1)))) * fTemp15) - (((fRec1[2] * (1 + ((fTemp17 - fTemp18) / fTemp16))) + (2 * (fRec1[1] * (1 - (1.0f / faustpower<2>(fTemp16)))))) / fTemp19));
			output0[i] = (FAUSTFLOAT)((fRec0[0] * (fRec1[0] + (fRec1[2] + (2 * fRec1[1])))) / fTemp19);
			output1[i] = (FAUSTFLOAT)fTemp15;
			// post processing
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec22[1] = fRec22[0];
			fRec26[1] = fRec26[0];
			fRec23[1] = fRec23[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec17[1] = fRec17[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec2[1] = fRec2[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec4[1] = fRec4[0];
			fRec0[1] = fRec0[0];
		}
	}
};


float 	OneVoice::ftbl0[65536];
float 	OneVoice::ftbl1[65536];
