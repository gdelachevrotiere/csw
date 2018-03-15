#include "Artifact.h"

Artifact::Artifact(const int& victoryPoints, const Impact& preModifier, const Impact& postModifier) {
    this->victoryPoints = victoryPoints;
    this->preModifier = preModifier;
    this->postModifier = postModifier;
}

int Artifact::get_victory_points() {
    return victoryPoints;
}

Impact Artifact::get_pre_modifier() {
    return preModifier;
}

Impact Artifact::get_post_modifier() {
    return postModifier;
}
