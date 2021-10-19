# Pure Data patch export to lv2 plugin using heavy compiler + dpf example 
*Work in progress* -
Takes an audio input and writes to a 0.5 seconds buffers. 4 buffers available that can be triggered within mod-ui mappings. Uses [Distrho Plugin Framework](https://github.com/DISTRHO/DPF)
intended to run on [MOD-Devices](https://moddevices.com/) / arm64 initially 

##### Install [heavy compiler](https://github.com/Wasted-Audio/hvcc)  :
```zsh
pip3 install hvcc 
```
##### Run the compiler against the pd patch with specific outputs and configs, gets DPF from github and compiles files specified in the json: lv2 , vst , jack app.
```zsh
git clone https://github.com/CarloCattano/Samplero.git
cd Samplero
rm dpf_mySamplero -rf    #removes previous builds in case I dont deal with gitignore well
hvcc Samplero.pd -o dpf_mySamplero -g dpf -n dpf_mySamplero -m dpf_samplero.json
cd dpf_mySamplero
git clone https://github.com/DISTRHO/DPF.git dpf
make
cd bin
cp -r dpf_mySamplero.lv2 ~/.lv2  # lv2 for mod folder
```
Then its just a matter of using [modsdk](https://github.com/moddevices/mod-sdk) for giving it an UI . I will try to leave a working example one here . Still trying to figure out how to make switches for toggles and triggers instead of knobs.

<a href="url"><img src="https://user-images.githubusercontent.com/17380530/137717628-b09fd3c5-1847-4442-bcae-466a013dd527.png" align="left" height="32%" width="32%" ></a><a href="url"><img src="https://user-images.githubusercontent.com/17380530/137720612-5b304b86-2700-4085-9603-d12467353aae.png" align="center" height="70%" width="70%"></a>
 

Note that the given plugins in the samplero/dpf_mySamplero/bin/ are built with an arm64/aarch64 GNU/Linux, and its recommended to remove the dpf_mySamplero folder and build on your own machine.

To do's :
- Midi input mappings 
- Default pitch value to match original recorded pitch at middle position or 0 position
- Add hanning for amplitude smoothing 
- Variable length record memory
- overdub ? 
- Fix click on buffer end while recording 

## DEMO VIDEO:
[![Watch the video](https://user-images.githubusercontent.com/17380530/137725252-57d0d03c-36a7-4a89-9b67-9af832fe1432.png)](https://www.youtube.com/watch?v=etJSJoM5gzQ)
