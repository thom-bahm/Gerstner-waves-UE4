# Place to think about how to do things / if I should do things

## Ideas:
* ProceduralMeshComponent moon that orbits landscape and has some neat effect on the WPO/normal distortion - 
Ideally it would have an atmosphere and have many parameters to adjust appearance combined w/ cool shader effect. 
* Implement super cheap water-types (different waves/ foam for Ocean/pond/lake) by taking the point at the middle
of the plane (or multiple points) and casting out 7 rays going from 0 -> 45 -> 90 -> 135... And if it's open water
(not closed in), its ocean, if points are within a specific range it's lake otherwise pond, etc.
