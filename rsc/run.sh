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
	pkill -SIGINT --echo "${PROG_PLAYER}"
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

for id in $(seq 1 "${NB_PLAYERS}"); do
	for team in "${TEAMS[@]}"; do
		printf "Starting player %d for team %d\n" "${id}" "${team}"
		"${PROG}" "${team}" "${AI}" >& "${DIR_LOG}/runner_${team}_${id}" &
		# "${PROG}" "${team}" "${AI}" >/dev/null &
	done
done

while true; do
	read -p "Press 'Ctrl+C' to quit: " -n 1 -r
done

clean
