# Place to think about what to do and how/if I should do it.

**(BS)** = Brainstorm / unreliabale and likely to change
## Game Ideas:
### Infinite ocean adventure game
* If I can get tesselation of ocean down efficiently and infinite ocean seems plausible potentially create an infinite ocean / procedural island game that could also make use of super cool procedural moons orbiting (Back story could be that stuff got destroyed on earth because something knocked us out of orbit and sent us on a fast slingshot or something, which is the reason for random moons and stuff passing by / orbiting earth. Could even pass saturn and stuff and have some cool moments like that if there was any story involved). 
* Game would essentially have to be an adventure/ exploration game but how do I make that unique? 
having cool story-driven storms that throw a wrench in plans could make it a little spicy and would show off nice waves which is the real plus.
* I would try to make graphics really nice but if I were doing procedural islands that's just unrealistic and probably super painstaking in ue4 with the custom node and all that. In OpenGL it would make more sense but I'm not going back now. Maybe I could just create a healthy selection of island heightmaps/ (maybe texture heatmaps too) from WorldCreator and procede to apply some noise filter or algorithm that could distort it's shape, size, and to some degree it's attributes while maintaining a somewhat realistic island.
* Maybe the starting point would be a really perfected island/ landscape created in WC, then from there on out it's just infinite and procedural. 
* Which engine to do this? 
This would be pretty hard especially since I generally dislike how ue4's custom shader and mesh system works. I feel like unity would be much easier but I don't want to have to learn a new editor and also language. Could make sense though, I'll look into the possibility. Definitely not going to OpenGL, far too much time if I ever want to finish something, even if I find it more fun.

### Zombie Game #1
* I've always liked the fps dying light type stuff, an interesting game idea could be to have a character who has amnesia / ends up in the woods with no memory (or memory of pre-apocalypse times), maybe in a hospital gown or whatever. Point of the game will be a mix of discovering the past but more importantly fighting through zombies to get back to a major living-people city ( once there the game ends, I don't wanna have to model all those buildings and streets.)
* The real decision in core gameplay would inolve pace, horror aspect, action aspect and adventure aspect:
- I could make it slow paced, more focused on discovering the past / whats going on - this would be a horror / adventure.
- I Could also make it fast paced focused on bashing zombies and running from them - this would be action.
- I would like to find a sweet spot of some to minimal horror mixed with some adventure, and a lot of action. Quests in this game would probably all contribute to the story as I don't want to model any real characters for side quests - if I had a basic crafting and inventory system, side quests could just be notes detailing the location of some resources. This would be nice but I don't want it to be based on inventory and collecting stuff, so I probably won't do that. Having some crafting would be good though, just to have some exterior motives to engage and explore. Maybe you start off the game with a small dagger on the first zombie you encounter or something.
* Names could be "Dead or forgotten", "The Path Back Home", "The Dead Are Not Forgotten", "The Dead Are Sleeping"(If horror), "Hit Or Run", "Bash and Dash"(if super-action). I personally like the first 2 most. 

* Don't know how difficult it will be to setup a satisfying bashing mechanic and animation for all that; also creating the zombies will be a large challenge for me. Not sure how realistic this is if I don't spend some bread. I feel confident that I could deal with environment looks and world creation with decent optimization, as well as the core health / death / damage systems. Animation and modelling are gonna be the hardest, I'll have to relearn blender and actually figure out a good workflow to easily create multiple zombies without spending an insane amount of time modelling and rigging, etc. I would ideally want gory execution animations too which I feel like could be realistic if modelling and animating doesn't take forever.
* Another main challenge for this would be creating urban environments in any sense, I would prefer a way to only have a nature environment and some log cabins, trailers, etc. Just unrealistic to envision creating a city landscape thats detailed and playable by myself. I'm confident creating a few building variations would not be a huge task though.

* Story idea: Make the backstory that you are on a different planet than earth and some virus on this planet got all the people infected, and that could be the big story reveal in the game.

## Specific Ideas/ Mechanics:
### Moon/ Procedural whatever:
* ProceduralMeshComponent moon that orbits landscape and has some neat effect on the WPO/normal distortion - 
Ideally it would have an atmosphere and have many parameters to adjust appearance combined w/ cool shader effect. 
* Create orbit for Moon shape by creating a radius from the center of the landscape and having it stay at that radius while the root component transforms around it
* Cool effect could be to have cracks that glow/ pulsate in the moon as if it were to explode, I could do that with noise porbably; Also having an atmosphere would be very nice if it doesn't take forever (don't think it will, should be pretty easy shader to research)
* If moon shapes up nicely and doesn't take ridiculous amount of time it could be cool to have a visible tidal effect if that makes any physical sense (also the orbit would have to be mad quick for it to be easily noticeable)

### Water stuff:
* **(BS)** Implement super cheap water-types (different waves/ foam for Ocean/pond/lake) by taking the point at the middle
of the plane (or multiple points) and casting out 7 rays going from 0 -> 45 -> 90 -> 135... And if it's open water
(not closed in), its ocean, if points are within a specific range it's lake otherwise pond, etc.
* Implement Beaufort scale based on distance from shore (Mention in ACIII article), Probably gonna want to implement FFT waves and foam, reflect/refraction first.
* **(BS)** Calculate wave direction based on shoreline vertices so that the direction is believable and actually dynamic along the waves.
* Figure out tesselation for obvious performance reasons if I intend to make very large or infinte ocean.
* **(BS)** Create lod system based on distance from shore that determines opacity, Depth tint and whether or not/how much to use fake SSS, reflection, translucency, and whatever else. there would only be 2-3 lods, shoreline, medium water, and deepwater - medium water is probably optional, if there's a convincing way to very smoothly transition from 
Shoreline/Shallow->Deepwater lods I wouldn't need it. 
* Make foam gather more right at the shoreline and then have little to no foam in shallow, followed by lots of foam in deep water.
* **probably just gonna finish Gerstner Waves and follow along with Tessendorf paper and then see where I'm at before doing any of this**
