# Place to think about what to do and how/if I should to do it.

## Game Ideas:
### Infinite ocean adventure game
* If I can get tesselation of ocean down efficiently and infinite ocean seems plausible potentially create an infinite ocean / procedural island game that could also make use of super cool procedural moons orbiting (Back story could be that stuff got destroyed on earth because something knocked us out of orbit and sent us on a fast slingshot or something, which is the reason for random moons and stuff passing by / orbiting earth. Could even pass saturn and stuff and have some cool moments like that if there was any story involved). 
* Game would essentially have to be an adventure/ exploration game but how do I make that unique? 
having cool story-driven storms that throw a wrench in plans could make it a little spicy and would show off nice waves which is the real plus.
* I would try to make graphics really nice but if I were doing procedural islands that's just unrealistic and probably super painstaking in ue4 with the custom node and all that. In OpenGL it would make more sense but I'm not going back now. Maybe I could just create a healthy selection of island heightmaps/ (maybe texture heatmaps too) from WorldCreator and procede to apply some noise filter or algorithm that could distort it's shape, size, and to some degree it's attributes while maintaining a somewhat realistic island.
* Maybe the starting point would be a really perfected island/ landscape created in WC, then from there on out it's just infinite and procedural. 
* Which engine to do this? 
This would be pretty hard especially since I generally dislike how ue4's custom shader and mesh system works. I feel like unity would be much easier but I don't want to have to learn a new editor and also language. Could make sense though, I'll look into the possibility. Definitely not going to OpenGL, far too much time if I ever want to finish something, even if I find it more fun.

## Specific Ideas/ Mechanics:
### Moon/ Procedural whatever:
* ProceduralMeshComponent moon that orbits landscape and has some neat effect on the WPO/normal distortion - 
Ideally it would have an atmosphere and have many parameters to adjust appearance combined w/ cool shader effect. 
* Create orbit for Moon shape by creating a radius from the center of the landscape and having it stay at that radius while the root component transforms around it
* Cool effect could be to have cracks that glow/ pulsate in the moon as if it were to explode, I could do that with noise porbably; Also having an atmosphere would be very nice if it doesn't take forever (don't think it will, should be pretty easy shader to research)
* If moon shapes up nicely and doesn't take ridiculous amount of time it could be cool to have a visible tidal effect if that makes any physical sense (also the orbit would have to be mad quick for it to be easily noticeable)

### Water stuff:
* Implement super cheap water-types (different waves/ foam for Ocean/pond/lake) by taking the point at the middle
of the plane (or multiple points) and casting out 7 rays going from 0 -> 45 -> 90 -> 135... And if it's open water
(not closed in), its ocean, if points are within a specific range it's lake otherwise pond, etc.
* Implement Beaufort scale based on distance from shore (Mention in ACIII article), Probably gonna want to implement FFT waves and foam, reflect/refraction first.
* Calculate wave direction based on shoreline vertices so that the direction is believable and actually dynamic along the waves.
* Figure out tesselation for obvious performance reasons if I intend to make very large or infinte ocean.
