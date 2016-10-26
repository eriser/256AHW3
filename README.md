# 256AHW3
Polyphonic Midi Synth PlugIn
by Mark Hertensteiner

see video (caution: very low record framerate) at https://www.youtube.com/watch?v=LIqbEw4QpGs&feature=youtu.be

Includes implementations of Modulation Wheel (CC1) and Pitch Bend, as well as Midi learn for CC messages from
Controller knobs / sliders - click Midi Learn button, move knob / slider on controller, move parameter you want
that knob / slider to control, and it's mapped!

Controllable synth parameters include Attack, Decay, Sustain, and Release of amplitude envelope; Cutoff Frequency and Resonance (Q)
of low-pass resonant filter; Vibrato Rate, Phase, and Strength; and Tremolo Rate, Phase, and Strength (Vibrato and Tremolo Phase 
are adjustable so Vibrato and Tremolo can have opposing phases if desired, or could be controlled by an LFO or automation 
in a DAW).  Both Vibrato and Tremolo are switchable between Off, On, or Mapped to Modulation Wheel (CC1).

The biggest missing feature is having the GUI update to reflect changes made by CC messages coming from the Midi controller.
I'd be interested in adding this feature, but at this stage I feel like it's complete enough to use in a performance or 
recording setting, and I'm just happy to have everything else working.
