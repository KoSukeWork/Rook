#include "RookPrivatePCH.h"
#include "RookAudioDataLoader.h"

bool URookAudioDataLoader::IsTickable() const {
	return true;
}

TStatId URookAudioDataLoader::GetStatId() const {
	return this->GetStatID();
}

void URookAudioDataLoader::Tick( float DeltaTime ) {
	if ( LoadingGraph.Num() != 0 ) {
		if ( LoadingGraph[0] != nullptr ) {
			if ( LoadingGraph[0]->IsComplete() ) {
				LoadingGraph.RemoveAt(0);
			}
		} else {
			LoadingGraph.RemoveAt(0);
		}
	}
}