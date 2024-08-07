A quick project to create semi-realistic waves in UE4 using the Gerstner Wave technique, using usf files (HLSL-based unreal engine shader language) and blueprints.

UE4 Version: Unfortunately don't have many screenshots from this one, however [some wireframe shots](https://github.com/thom-bahm/Gerstner-waves-UE4/blob/main/README.md#screenshots) are still around

## Sources / Information

#### Articles
* [Tessendorf Paper](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.161.9102&rep=rep1&type=pdf)
* [1986 Article "A Simple Model Of Ocean Waves" Written by Fournier](http://users.encs.concordia.ca/~grogono/Graphics/waves-1.pdf) - basically about gerstner waves
* [partial C++ Adaptation of Tessendorf Paper](https://www.scratchapixel.com/lessons/procedural-generation-virtual-worlds/simulating-odean-waves/simulating-surface-ocean)
* [Nvidia GPU Gems, Gerstner Waves](https://developer.nvidia.com/gpugems/gpugems/part-i-natural-effects/chapter-1-effective-water-simulation-physical-models)
* [Assassins Creed](https://www.fxguide.com/fxfeatured/assassins-creed-iii-the-tech-behind-or-beneath-the-action/)

#### Videos
* [Fourier Transform concept 3blue1brown](https://www.youtube.com/watch?v=spUNpyF58BY&list=PLJPAgezdQHRH8PKECjIxSL-CBmB8k-2nR&index=2)
* [Intro to Fast Fourier Transform](https://www.youtube.com/watch?v=P4G0hn5QhMs), 
[Slideshow Associated With Video](https://www.slideshare.net/Codemotion/an-introduction-to-realistic-ocean-rendering-through-fft-fabio-suriano-codemotion-rome-2017)
* [Brief Video About Gerstner Waves](https://www.youtube.com/watch?v=V4yZigMSLiU&list=PLJPAgezdQHRH8PKECjIxSL-CBmB8k-2nR&index=1)
* [Gerstner Waves using blueprint in ue4.](https://www.youtube.com/watch?v=ANaER2rvd9M&list=PLJPAgezdQHREuUxXIzpBaGWLBYRJomN_l&index=2)
* [Mathematical Ocean For Buoyancy, Blueprint in ue4](https://www.youtube.com/watch?v=spUNpyF58BY&list=PLJPAgezdQHRH8PKECjIxSL-CBmB8k-2nR&index=2)
* [Goal video, what I'd ideall be able to acheive (Real-time FFT Ocean rendering done in OpenGL w/ AMD Readon R7 360, which is 3 times slower than gtx 1070)](https://www.youtube.com/watch?v=CeJCNmI-B7s&list=PLJPAgezdQHREseDfQ5LaUd5Sn3ONhlXEL&index=1)
* [Another goal video](https://www.youtube.com/watch?v=OQ3D0Q5BlOs&list=PLJPAgezdQHREseDfQ5LaUd5Sn3ONhlXEL&index=2)


#### Screenshots

Here's some screenshots of the wireframe on a restricted plane with the shaders applied as a material.
![Wireframe top view](https://github.com/thom-bahm/Gerstner-waves-UE4/blob/main/wireframe_0.png)
![Wireframe side view](https://github.com/thom-bahm/Gerstner-waves-UE4/blob/main/wireframe_1.png)
