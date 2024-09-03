#!/bin/bash

PROG="${PWD}/lemipc"

if [ ! -f "${PROG}" ]; then
	echo "Executable not found: ${PROG}"
	exit 1
fi

PROG_PLAYER="lemipc"
PROG_PLAYER="${PROG_PLAYER}_$(tr -dc A-Za-z0-9 </dev/urandom | head -c 4; echo)"
cp "${PROG}" "${PWD}/rsc/${PROG_PLAYER}"

PROG="${PWD}/rsc/${PROG_PLAYER}"

DIR_LOG="${PWD}/rsc/log"

[ ! -d "${DIR_LOG}" ] && mkdir -p "${DIR_LOG}"

function	clean()
{
	pkill --signal SIGINT --echo "${PROG_PLAYER}"
	rm -f "${PROG}"
	exit 130
}

trap "echo; clean" SIGINT

NB_PLAYERS="${1:-1}"
TEAM="${2:-1}"
AI="${3:-}"

if [[ ${TEAM} =~ ^[0-9]+$ ]]; then
	TEAMS=("${TEAM}")
else
	TEAMS=($(seq "${TEAM%-*}" "${TEAM#*-}"))
fi

declare -A	ALGO_PROFILE=(
	["1"]=hard
	["2"]=hard
	["3"]=hard
	["4"]=medium
	["5"]=medium
	["6"]=medium
	["7"]=medium
	["8"]=medium
)

for id in $(seq 1 "${NB_PLAYERS}"); do
	for team in "${TEAMS[@]}"; do
		if [ "${AI}" == "use_profile" ]; then
			tmp_ai="${ALGO_PROFILE[${team}]}"
		else
			tmp_ai="${AI}"
		fi
		printf "Starting player %d for team %d (AI: %s)\n" "${id}" "${team}" "${tmp_ai}"
		# "${PROG}" "${team}" "${tmp_ai}" >& "${DIR_LOG}/runner_${id}_${team}" &
		"${PROG}" "${team}" "${tmp_ai}" >& "${DIR_LOG}/runner_${team}_${id}" &
		# "${PROG}" "${team}" "${tmp_ai}" >/dev/null &
	done
done

while true; do
	read -p "Press 'Ctrl+C' to quit: " -n 1 -r
done

clean
