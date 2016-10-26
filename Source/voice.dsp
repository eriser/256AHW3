import("stdfaust.lib");

freq = vslider("freq",440,20,20000,0.01);
gain = vslider("gain",0.5,0,1,0.01) : si.smoo;


attack = vslider("att", 0.1, 0, 2, 0.0001) : si.smoo;
delay = vslider("del", 0.1, 0, 2, 0.0001) : si.smoo;
sustain = vslider("sus", 75, 0, 100, 0.1) : si.smoo;
release = vslider("rel", 0.5, 0, 4, 0.0001) : si.smoo;
trigger = checkbox("trig");
env = en.adsr(attack,delay,sustain,release, trigger):_;


cutoff = vslider("cutoff", 9, 0, 9, 0.001) : si.smoo;
cfreq = 20*(2^cutoff);
reson = vslider("Q", 7, 1, 20, 0.001) : si.smoo;

vibrate = vslider("vibrate", 6, 2, 10, 0.001) : si.smoo;
vibstr = vslider("vibstr", 0.5, 0, 1, 0.001) : si.smoo;
vibMWOn = checkbox("vibMWOn") : si.smoo;
vibPhase = vslider("vibPhase", 0, 0, 1, 0.0001) : si.smoo;

tremrate = vslider("tremrate", 6, 2, 10, 0.001) : si.smoo;
tremstr = vslider("tremstr", 0.5, 0, 1, 0.001) : si.smoo;
tremMWOn = checkbox("tremMWOn") : si.smoo;
tremPhase = vslider("tremPhase", 0, 0, 1, 0.001) :si.smoo;

pBend = vslider("pitchBend", 0, -2, 2, 0.00005) :si.smoo;
modWheel = vslider("modWheel", 0, 0, 127, 1) : si.smoo;

vibOn = checkbox("vibOn") : si.smoo;
tremOn = checkbox("tremOn") : si.smoo;



process = hgroup("voice",  os.sawtooth(freq*(2^(pBend/12)) + (os.oscp(vibrate, 2*ma.PI*vibPhase) * vibstr  * 10 * (vibOn + (vibMWOn * modWheel)))) * ((((os.oscp(tremrate,2*ma.PI*tremPhase) * 0.5) + 0.5)*tremstr*(tremOn+(tremMWOn*modWheel)))+(1-tremstr*(tremOn + (tremMWOn * modWheel)))) * gain * env : fi.resonlp(cfreq,reson,gain),env );
