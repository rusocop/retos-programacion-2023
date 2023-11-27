const rules = {
	'🗿': ['✂️', '🦎'],
	'📄': ['🗿', '🖖'],
	'✂️': ['📄', '🦎'],
	'🦎': ['🖖', '📄'],
	'🖖': ['🗿', '✂️'],
};

const game = (gameSequence) => {
	let message = '';
	let player1 = 0;
	let player2 = 0;
	const winningPoints = 3;

	for (const play of gameSequence) {
		const [inputPlayer1, inputPlayer2] = play;

		if (player1 >= winningPoints || player2 >= winningPoints) break;

		console.log(`${inputPlayer1} | ${inputPlayer2}`);

		if (inputPlayer1 === inputPlayer2) continue;

		rules[inputPlayer1].includes(inputPlayer2) ? player1++ : player2++;
	}

	if (player1 === player2) {
		message = 'Tie';
	} else {
		message = player1 > player2 ? 'Winner is player 1' : 'Winner is player 2';
	}

	console.log(message);
};

const gameSequence = [
	['🗿', '✂️'],
	['✂️', '🗿'],
	['📄', '✂️'],
	['🗿', '✂️'],
	['✂️', '🗿'],
	['📄', '✂️'],
];

game(gameSequence); //Winner player 2
