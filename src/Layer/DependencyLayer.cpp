//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "DependencyLayer.h"

/**
 * Constructor for the dependency layer. Dependency layer stores the dependency information of a node.
 * @param layerValue Value of the dependency layer.
 */
DependencyLayer::DependencyLayer(const string &layerValue) {
    layerName = "dependency";
    setLayerValue(layerValue);
}
