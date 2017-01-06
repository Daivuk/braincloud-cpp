// Copyright 2016 bitHeads, Inc. All Rights Reserved.

#pragma once

#include <string>
#include "braincloud/BrainCloudTypes.h"

namespace BrainCloud
{
	class IServerCallback;
	class BrainCloudClient;

	class BrainCloudTournament
	{
	public:
		BrainCloudTournament(BrainCloudClient* in_client);

		/**
		 * Processes any outstanding rewards for the given player
		 *
		 * Service Name - tournament
		 * Service Operation - CLAIM_TOURNAMENT_REWARD
		 *
		 * @param in_leaderboardId The leaderboard for the tournament
		 * @param in_versionId Version of the tournament. Use -1 for the latest version.
		 * @param in_callback The method to be invoked when the server response is received
		 */
		void claimTournamentReward(const char* in_leaderboardId, int32_t in_versionId, IServerCallback * in_callback = NULL);

		/**
		 * Get tournament status associated with a leaderboard
		 *
		 * Service Name - tournament
		 * Service Operation - GET_TOURNAMENT_STATUS
		 *
		 * @param in_leaderboardId The leaderboard for the tournament
		 * @param in_versionId Version of the tournament. Use -1 for the latest version.
		 * @param in_callback The method to be invoked when the server response is received
		 */
		void getTournamentStatus(const char* in_leaderboardId, int32_t in_versionId, IServerCallback * in_callback = NULL);

		/**
		 * Join the specified tournament.
		 * Any entry fees will be automatically collected.
		 *
		 * Service Name - tournament
		 * Service Operation - JOIN_TOURNAMENT
		 *
		 * @param in_leaderboardId The leaderboard for the tournament
		 * @param in_tournamentCode Tournament to join
		 * @param in_initialScore Initial score for the user
		 * @param in_callback The method to be invoked when the server response is received
		 */
		void joinTournament(const char* in_leaderboardId, const char* in_tournamentCode, int32_t in_initialScore, IServerCallback * in_callback = NULL);

		/**
		 * Removes player's score from tournament leaderboard
		 *
		 * Service Name - tournament
		 * Service Operation - LEAVE_TOURNAMENT
		 *
		 * @param in_leaderboardId The leaderboard for the tournament
		 * @param in_callback The method to be invoked when the server response is received
		 */
		void leaveTournament(const char* in_leaderboardId, IServerCallback * in_callback = NULL);

		/**
		 * Post the users score to the leaderboard
		 *
		 * Service Name - tournament
		 * Service Operation - POST_TOURNAMENT_SCORE
		 *
		 * @param in_leaderboardId The leaderboard for the tournament
		 * @param in_score The score to post
		 * @param in_jsonData Optional data attached to the leaderboard entry
		 * @param in_roundStartedTime Time the user started the match resulting in the score being posted.
		 * @param in_callback The method to be invoked when the server response is received
		 */
		void postTournamentScore(const char* in_leaderboardId, int32_t in_score, const std::string& in_jsonData, const struct tm* in_roundStartedTime, IServerCallback * in_callback = NULL);

		/**
		 * Returns the user's expected reward based on the current scores
		 *
		 * Service Name - tournament
		 * Service Operation - VIEW_CURRENT_REWARD
		 *
		 * @param in_leaderboardId The leaderboard for the tournament
		 * @param in_callback The method to be invoked when the server response is received
		 */
		void viewCurrentReward(const char* in_leaderboardId, IServerCallback * in_callback = NULL);

		/**
		 * Returns the user's reward from a finished tournament
		 *
		 * Service Name - tournament
		 * Service Operation - VIEW_REWARD
		 *
		 * @param in_leaderboardId The leaderboard for the tournament
		 * @param in_versionId Version of the tournament. Use -1 for the latest version.
		 * @param in_callback The method to be invoked when the server response is received
		 */
		void viewReward(const char* in_leaderboardId, int32_t in_versionId, IServerCallback * in_callback = NULL);

	private:
		BrainCloudClient * m_client;
	};
}